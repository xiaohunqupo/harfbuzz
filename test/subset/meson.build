tests = [
  'basics',
  'bidi',
  'cmap',
  'cmap14',
  'cmap4_overflow',
  'preprocess',
  'full-font',
  'cff-full-font',
  'japanese',
  'cff-japanese',
  'cff.notoserifmyanmar',
  'glyf_bug_3131',
  'layout',
  'layout.gpos',
  'layout.gpos2',
  'layout.gpos3',
  'layout.gpos4',
  'layout.gpos5',
  'layout.gpos6',
  'layout.gpos8',
  'layout.gpos8.amiri',
  'layout.gpos9',
  'layout.gsub3',
  'layout.gsub5',
  'layout.gsub5_format2',
  'layout.gsub6',
  'layout.gsub8',
  'layout.gdef',
  'layout.gdef.glyphset',
  'layout.khmer',
  'layout.context',
  'layout.context_format2',
  'layout.gdef-varstore',
  'layout.gdef-attachlist',
  'layout.notonastaliqurdu',
  'layout.tinos',
  'layout.duplicate_features',
  'layout.unsorted_featurelist',
  'layout.drop_feature',
  'no_layout_closure',
  'sbix',
  'colr',
  'colr_glyphs',
  'math',
  'math_coverage_offset',
  'subset_base',
  # TODO: re-enable once colrv1 subsetting is stabilized.
  # 'colrv1.notoemoji',
  'colrv1',
  'colrv1_subset_varstore',
  'colr_with_components',
  'cbdt',
  'variable',
  'glyph_names',
  'glyph_map',
  'post',
  '32bit_var_store',
  'pin_all_at_default',
  'instantiate_base',
  'instantiate_colrv1',
  'instantiate_glyf',
  'instantiate_cff2',
  'instantiate_cff2_tsb',
  'full_instance',
  'instance_feature_variations',
  'instance_no_double_free',
  'mvar_full_instance',
  'instance_comp_glyph_empty_child',
  'post_apply_mvar_delta',
  'apply_cvar_delta',
  'collect_name_ids',
  'instantiate_cff2_update_metrics',
  'layout.empty_ligature_offset',
  'glyf_partial_instancing',
  'mvar_partial_instance',
  'update_def_wght',
  'feature_variations_partial_instance',
  'gdef_partial_instance',
  'value_format_partial_instance',
  'feature_variation_instance_collect_lookups',
  'sync_vmetrics',
  'empty_region_vardata',
  'colrv1_partial_instance',
  'instantiate_gvar_padding',
]

if get_option('experimental_api')
  tests += [
    'iftb_requirements',
  ]
endif

repack_tests = [
  'basic',
  'prioritization',
  'table_duplication',
  'isolation',
  'advanced_prioritization',
  'space_splitting',
]

run_test = find_program('run-tests.py')

foreach t : tests
  fname = '@0@.tests'.format(t)

  test(t, run_test,
    args: [
      hb_subset,
      meson.current_source_dir() / 'data' / 'tests' / fname,
    ],
    # as the tests are ran concurrently let's raise acceptable time here
    # ideally better to break and let meson handles them in parallel
    timeout: 500,
    workdir: meson.current_build_dir() / '..' / '..',
    protocol: 'tap',
    suite: 'subset',
  )
endforeach

run_repack_test = find_program('run-repack-tests.py')

foreach t : repack_tests
  fname = '@0@.tests'.format(t)

  test(t, run_repack_test,
    args: [
      hb_subset,
      meson.current_source_dir() / 'data' / 'repack_tests' / fname,
    ],
    workdir: meson.current_build_dir() / '..' / '..',
    protocol: 'tap',
    suite: ['subset', 'repack'],
  )
endforeach
