include_directories(..)

set(EXPRESS_CORE_OBJ
    $<TARGET_OBJECTS:objlib_alloc_c>
    $<TARGET_OBJECTS:objlib_memory_c>
    $<TARGET_OBJECTS:objlib_factory_c>
    $<TARGET_OBJECTS:objlib_error_c>
    $<TARGET_OBJECTS:objlib_hash_c>
    $<TARGET_OBJECTS:objlib_linklist_c>
# extra
    $<TARGET_OBJECTS:objlib_dict_c>
    $<TARGET_OBJECTS:objlib_object_c>
    $<TARGET_OBJECTS:objlib_info_c>
)

add_executable(test_expr test_expr.c $<TARGET_OBJECTS:objlib_expr_c> ${EXPRESS_CORE_OBJ})
add_test(NAME expr_resolve_op_dot COMMAND test_expr resolve_op_dot) 

add_executable(check-hash "hash_test.c;../hash.c;../../auxlib/bstrlib.c")
set_property(TARGET check-hash PROPERTY COMPILE_DEFINITIONS "HASH_TESTING;HASH_DEBUG")
target_link_libraries(check-hash "m")

add_test(NAME test_hash_impl
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
  COMMAND $<TARGET_FILE:check-hash> "${CMAKE_CURRENT_SOURCE_DIR}/hash_names.txt"
  )

add_test(NAME build_check_express
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMAND ${CMAKE_COMMAND} --build .
    --target check-express
    --config $<CONFIGURATION>
    )

add_test(NAME test_plib_parse_err
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
  COMMAND $<TARGET_FILE:check-express> "${CMAKE_CURRENT_SOURCE_DIR}/plib_parse_err.exp"
  )

set_tests_properties( test_plib_parse_err PROPERTIES DEPENDS "test_hash_impl" )
set_tests_properties( test_plib_parse_err test_plib_parse_err PROPERTIES LABELS parser )

sc_addexec(print_schemas "../fedex.c;print_schemas.c" "express;base")
sc_addexec(print_attrs "../fedex.c;print_attrs.c" "express;base")

# Local Variables:
# tab-width: 8
# mode: cmake
# indent-tabs-mode: t
# End:
# ex: shiftwidth=2 tabstop=8

