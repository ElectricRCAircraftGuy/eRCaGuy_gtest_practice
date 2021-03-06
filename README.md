# eRCaGuy_gtest_practice
googletest (gtest) & googlemock (gmock) practice

# Author
Gabriel Staples  
www.ElectricRCAircraftGuy.com

# Status
It works! I am able to successfully write and run google tests and mocks. Follow Build & Run instructions below.  

# Cross-references
1. Inspired by this question, "**[google mock - can I call EXPECT_CALL multiple times on same mock object?](https://stackoverflow.com/questions/44034633/google-mock-can-i-call-expect-call-multiple-times-on-same-mock-object)**", and [my big Stack Overflow answer to it here](https://stackoverflow.com/questions/44034633/google-mock-can-i-call-expect-call-multiple-times-on-same-mock-object/60905880#60905880)
1. and my big discussion with @luantkow under [his answer here](https://stackoverflow.com/questions/44034633/google-mock-can-i-call-expect-call-multiple-times-on-same-mock-object/44035118#44035118), as well as on [his code gist (under GitHub username @lukant) here](https://gist.github.com/lukant/376df8c49a3aba8179879fadcea77dea).

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

## In short:

    time bazel test --test_output=errors --test_arg=--gtest_color=yes //...             # run ALL tests
    time bazel test --test_output=errors --test_arg=--gtest_color=yes //:gmock_test1    # run only test 1
    time bazel test --test_output=errors --test_arg=--gtest_color=yes //:gmock_test2    # run only test 2

## Details:

    time bazel test //...           # run ALL tests
    time bazel test //:gmock_tests  # run tests for just this "gmock_tests" target

To log all errors (failed test results) to stdout, add `--test_output errors`. See: https://groups.google.com/forum/#!topic/bazel-discuss/2mJPklIaCeo and see `bazel help test` for additional options. Ex:

    time bazel test --test_output errors //...  # log all errors (failed test results) to stdout 

To log all output (failed AND passed results) to stdout, add `--test_output all`. Ex:

    time bazel test --test_output all //...     # log ALL output (both failed & passed test results) to stdout 

But, this is drab! I want to <span style="color:red">**see the failures in red**</span> when they occur! To do that, we need to add the `--gtest_color=yes` option to the test binary when it is called. Do that with the bazel `--test_arg` option: `--test_arg=--gtest_color=yes`. The final command will now look like this:

    time bazel test --test_output=errors --test_arg=--gtest_color=yes //... 

Note that you can also *manually* pass these flags to a binary you have successfully built, such as `bazel-bin/gmock_tests`, as follows:

    bazel-bin/gmock_tests --gtest_color=yes

**References:**

1. Use the bazel `--test_arg` option to pass arguments to tests! https://stackoverflow.com/questions/50877601/how-to-pass-custom-flags-to-bazel-test-command/50890446#50890446
1. Pass `--gtest_color=yes` to any test binary to see colored output: https://github.com/google/googletest/blob/master/googletest/docs/advanced.md#controlling-test-output
1. If bazel isn't outputting color for some reason add this after the `bazel build` or `bazel test` command as well: `--color=yes`; see: https://docs.bazel.build/versions/master/user-manual.html#flag--color
1. Add color to text in markdown (ie: here is how I added red to this readme itself): https://stackoverflow.com/questions/35465557/how-to-apply-color-in-markdown/43355451#43355451

# Other bazel commands:

    bazel query //... # query for a list of all possible build targets 

# Adding your own test:

Just create your own `.cpp` test file or a `.h`/`.cpp` test file pair with some tests in it. Then, modify the `BUILD.bazel` file, either adding your new `.h` and `.cpp` files to the `srcs` list in an existing `cc_test`, or creating a new `cc_test` specifically for your new test files. 

