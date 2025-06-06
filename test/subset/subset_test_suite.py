#!/usr/bin/env python3

import os


# A single test in a subset test suite. Identifies a font
# a subsetting profile, and a subset to be cut.
class Test:
    def __init__(
        self, font_path, profile_path, subset, instance, iup_optimize, options
    ):
        self.font_path = font_path
        self.profile_path = profile_path
        self.subset = subset
        self.instance = instance
        self.iup_optimize = iup_optimize
        self.options = options

    def __str__(self):
        # Don't print self.subset as contains non-ASCII and some CI's don't like it
        return "Test: %s %s %s %s %s" % (
            self.font_path,
            self.profile_path,
            self.instance,
            self.iup_optimize,
            self.options,
        )

    def unicodes(self):
        import re

        if self.subset == "*":
            return self.subset[0]
        elif self.subset == "no-unicodes":
            return ""
        elif re.match(r"^U\+", self.subset):
            s = re.sub(r"U\+", "", self.subset)
            return s
        else:
            return ",".join("%X" % ord(c) for (i, c) in enumerate(self.subset))

    def instance_name(self):
        if not self.instance:
            return self.instance
        else:
            s = "." + self.instance.replace(":", "-")
            if self.iup_optimize:
                s += ".iup_optimize"
            return s

    def get_profile_flags(self):
        with open(self.profile_path, mode="r", encoding="utf-8") as f:
            return f.read().splitlines()

    def get_instance_flags(self):
        if not self.instance:
            return []
        else:
            return self.instance.split(",")

    def get_font_name(self):
        font_base_name = os.path.basename(self.font_path)
        font_base_name_parts = os.path.splitext(font_base_name)
        profile_name = os.path.splitext(os.path.basename(self.profile_path))[0]

        if self.unicodes() == "*":
            return "%s.%s.all%s%s" % (
                font_base_name_parts[0],
                profile_name,
                self.instance_name(),
                font_base_name_parts[1],
            )
        elif self.unicodes() == "":
            return "%s.%s.no-unicodes%s%s" % (
                font_base_name_parts[0],
                profile_name,
                self.instance_name(),
                font_base_name_parts[1],
            )
        else:
            return "%s.%s.%s%s%s" % (
                font_base_name_parts[0],
                profile_name,
                self.unicodes(),
                self.instance_name(),
                font_base_name_parts[1],
            )

    def get_font_extension(self):
        font_base_name = os.path.basename(self.font_path)
        font_base_name_parts = os.path.splitext(font_base_name)
        return font_base_name_parts[1]


# A group of tests to perform on the subsetter. Each test
# Identifies a font a subsetting profile, and a subset to be cut.
class SubsetTestSuite:

    def __init__(self, test_path, definition):
        self.test_path = test_path
        self.fonts = []
        self.profiles = []
        self.subsets = []
        self.instances = []
        self.options = []
        self.iup_options = []
        self._parse(definition)

    def get_output_directory(self):
        test_name = os.path.splitext(os.path.basename(self.test_path))[0]
        data_dir = os.path.join(os.path.dirname(self.test_path), "..")

        output_dir = os.path.normpath(os.path.join(data_dir, "expected", test_name))
        if not os.path.exists(output_dir):
            os.mkdir(output_dir)
        if not os.path.isdir(output_dir):
            raise Exception("%s is not a directory." % output_dir)

        return output_dir

    def tests(self):
        for font in self.fonts:
            font = os.path.join(self._base_path(), "fonts", font)
            for profile in self.profiles:
                profile = os.path.join(self._base_path(), "profiles", profile)
                for subset in self.subsets:
                    if self.instances:
                        for instance in self.instances:
                            if self.iup_options:
                                for iup_option in self.iup_options:
                                    yield Test(
                                        font,
                                        profile,
                                        subset,
                                        instance,
                                        iup_option == "Yes",
                                        options=self.options,
                                    )
                            else:
                                yield Test(
                                    font,
                                    profile,
                                    subset,
                                    instance,
                                    False,
                                    options=self.options,
                                )
                    else:
                        yield Test(
                            font, profile, subset, "", False, options=self.options
                        )

    def _base_path(self):
        return os.path.dirname(os.path.dirname(self.test_path))

    def _parse(self, definition):
        destinations = {
            "FONTS:": self.fonts,
            "PROFILES:": self.profiles,
            "SUBSETS:": self.subsets,
            "INSTANCES:": self.instances,
            "OPTIONS:": self.options,
            "IUP_OPTIONS:": self.iup_options,
        }

        current_destination = None
        for line in definition.splitlines():
            line = line.strip()

            if line.startswith("#"):
                continue

            if not line:
                continue

            if line in destinations:
                current_destination = destinations[line]
            elif current_destination is not None:
                current_destination.append(line)
            else:
                raise Exception("Failed to parse test suite file.")
