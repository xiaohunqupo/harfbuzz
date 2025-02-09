#!/usr/bin/env python3
import os
import sys
import subprocess
import tempfile


def run_command(command):
    """
    Run a command, capturing potentially large output in a temp file.
    Returns (output_string, exit_code).
    """
    with tempfile.TemporaryFile() as tempf:
        p = subprocess.Popen(command, stdout=tempf, stderr=tempf)
        p.wait()
        tempf.seek(0)
        output = tempf.read().decode("utf-8", errors="replace")
    return output, p.returncode


def chunkify(lst, chunk_size=64):
    """
    Yield successive chunk_size-sized slices from lst.
    """
    for i in range(0, len(lst), chunk_size):
        yield lst[i:i + chunk_size]


def gather_files(directory):
    """
    Return a list of *all* files (not subdirs) in `directory`.
    If `directory` doesn’t exist, returns an empty list.
    """
    if not os.path.isdir(directory):
        return []
    return [
        os.path.join(directory, f)
        for f in os.listdir(directory)
        if os.path.isfile(os.path.join(directory, f))
    ]
