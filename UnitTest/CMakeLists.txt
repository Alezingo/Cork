
#FetchContent_Declare(
#  googletest
#  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
#)

# For Windows: Prevent overriding the parent project's compiler/linker settings
#set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
#FetchContent_MakeAvailable(googletest)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.0.0-preview3)

FetchContent_MakeAvailable(Catch2)

FetchContent_Declare(
  EigenTemplateLibrary
  GIT_REPOSITORY https://gitlab.com/libeigen/eigen.git
  GIT_TAG        3.4.0)

FetchContent_MakeAvailable(EigenTemplateLibrary)

FetchContent_Declare(
  Xoshiro256PlusSIMD
  GIT_REPOSITORY https://github.com/stephanfr/Xoshiro256PlusSIMD.git
  GIT_TAG        main)

FetchContent_MakeAvailable(Xoshiro256PlusSIMD)


include_directories(
    ../src
    ../include
    ../thirdparty/tbb/${TBB_VERSION}/include
    ../thirdparty/mpir/${MPIR_VERSION}
    ${eigentemplatelibrary_SOURCE_DIR}
    ${xoshiro256plussimd_SOURCE_DIR}/include
)

add_executable( tests
  exterior_calculus_test.cpp
  performance_stream_test.cpp
  off_file_io_test.cpp
  CachingFactoryTest.cpp
  ConstructOnceResizeableVectorTest.cpp
  Vector2DTest.cpp
  Vector3DTest.cpp
  topology_tests.cpp
  geometric_tests.cpp
  triangulator_test.cpp
  surface_mesh_tests.cpp
  polygon_tests.cpp
  boundary_edge_tests.cpp
  svd_centroid_3d_tests.cpp
  topo_cache_tests.cpp
)

target_link_libraries(tests PRIVATE Catch2::Catch2WithMain Corklib tbb mpir boost_program_options boost_filesystem boost_iostreams boost_system boost_timer boost_thread pthread)

add_executable( benchmarks
  bounding_box_benchmark.cpp
  UnionFindBenchmark.cpp
  Vector3DBenchmark.cpp
  performance_stream_benchmark.cpp
  exterior_calculus_benchmark.cpp
)

target_link_libraries(benchmarks PRIVATE Catch2::Catch2WithMain Corklib tbb mpir boost_program_options boost_filesystem boost_system boost_timer boost_thread pthread)


list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)

include(CTest)
include(Catch)

catch_discover_tests( tests )
catch_discover_tests( benchmarks )