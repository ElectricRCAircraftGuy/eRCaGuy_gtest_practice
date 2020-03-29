# eRCaGuy_gtest_practice
googletest (gtest) & googlemock (gmock) practice

# Author
Gabriel Staples  
www.ElectricRCAircraftGuy.com

# Status
It works! I am able to successfully write and run google tests and mocks. Follow Build & Run instructions below.  

See also: https://stackoverflow.com/questions/44034633/google-mock-can-i-call-expect-call-multiple-times-on-same-mock-object/60905880#60905880

# To Build (Ubuntu instructions):
1. Install Bazel: https://docs.bazel.build/versions/master/install-ubuntu.html
1. Download the [latest Googletest release from here](https://github.com/google/googletest/releases) (I used v1.10.0). Extract it. Now you have a "googletest-release-1.10.0" directory. Symbolically link it into this project as follows:
    
        cd eRCaGuy_gtest_practice/googletest
        ln -si /path/to/folder/googletest-release-1.10.0 .

1. Ensure you are in the "eRCaGuy_gtest_practice" dir, and run the bazel build command:

        time bazel build //...  # Build ALL build targets

    Here's a sample of successful output:

        $ time bazel build //...
        INFO: Analyzed target //:gmock_tests (0 packages loaded, 0 targets configured).
        INFO: Found 1 target...
        Target //:gmock_tests up-to-date:
          bazel-bin/gmock_tests
        INFO: Elapsed time: 0.316s, Critical Path: 0.01s
        INFO: 0 processes.
        INFO: Build completed successfully, 1 total action

        real    0m0.408s
        user    0m0.024s
        sys 0m0.024s

# To run the tests

    time bazel test //...           # run ALL tests
    time bazel test //:gmock_tests  # run tests for just this target

# Other bazel commands:

    bazel query //... # query for a list of all possible build targets 

