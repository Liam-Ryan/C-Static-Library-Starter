#include <check.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <library.h>

//global for tests
FILE *stream;
char *streamData;
size_t size;

void setup(void)
{
	//set up before each test
	stream = open_memstream(&streamData, &size);
}

void teardown(void)
{
	//clean up after each test
	free(streamData);
}

START_TEST(hello_world)
	{
		if (!stream)
			ck_abort_msg("Error allocating memory for stream");
		int s = hello(stream);
		if (!s)
			ck_abort_msg("hello returned error message");
		fclose(stream);
		ck_assert_str_eq(streamData, "Hello, World!\n");
	}
END_TEST

START_TEST(one_equals_one)
	{
		ck_assert_str_eq("one", "one");
	}
END_TEST

START_TEST(true_is_true)
	{
		ck_assert(true == true);
	}
END_TEST

Suite *unit_tests(void)
{
	Suite *s = suite_create("Sample Unit Tests");

	TCase *tc_core = tcase_create("Core Test Case");
	//associate the setup and teardown functions with the test case
	tcase_add_checked_fixture(tc_core, setup, teardown);
	tcase_add_test(tc_core, hello_world);
	suite_add_tcase(s, tc_core);

	//notice case two doesn't use the setup or teardown
	TCase *tc_another = tcase_create("Another Test Case");
	tcase_add_test(tc_another, one_equals_one);
	tcase_add_test(tc_another, true_is_true);
	suite_add_tcase(s, tc_another);

	return s;
}


int main()
{
	int number_failed;
	Suite *s;
	SRunner *sr;

	s = unit_tests();
	sr = srunner_create(s);

	//Uncomment if you wish to debug unit tests or run valgrind on this file
	srunner_set_fork_status(sr, CK_NOFORK);

	srunner_run_all(sr, CK_NORMAL);
	number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);
	return number_failed < 1 ? EXIT_SUCCESS : EXIT_FAILURE;
}