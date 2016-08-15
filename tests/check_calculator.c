#include <stdlib.h>
#include <stdint.h>
#include <check.h>
#include "../src/roman_calculator.h"


START_TEST (test_core)
{
  //Test cases for addition operation
  ck_assert_str_eq(addition_operation("M","MM"), "MMM");
  ck_assert_str_eq(addition_operation("CCC","CD"), "DCC");
  ck_assert_str_eq(addition_operation("D","DC"), "MC");
  ck_assert_str_eq(addition_operation("CD","D"), "CM");
  ck_assert_str_eq(addition_operation("CM","M"), "MCM");
  ck_assert_str_eq(addition_operation("DCC","CM"), "MDC");
  ck_assert_str_eq(addition_operation("DCCC","DCC"), "MD");
  ck_assert_str_eq(addition_operation("CM","MM"), "MMCM");
  ck_assert_str_eq(addition_operation("CCC","CM"), "MCC");
  ck_assert_str_eq(addition_operation("M","X"), "MX");
  ck_assert_str_eq(addition_operation("CCC","L"), "CCCL");
  ck_assert_str_eq(addition_operation("LXXX","CCC"), "CCCLXXX");
  ck_assert_str_eq(addition_operation("XC","XCVIII"), "CLXXXVIII");
  ck_assert_str_eq(addition_operation("L","I"), "LI");
  ck_assert_str_eq(addition_operation("C","CI"), "CCI");
  ck_assert_str_eq(addition_operation("LXXX","XC"), "CLXX");
  ck_assert_str_eq(addition_operation("IV","V"), "IX");
  ck_assert_str_eq(addition_operation("V","V"), "X");
  ck_assert_str_eq(addition_operation("IX","X"), "XIX");
  ck_assert_str_eq(addition_operation("X","X"), "XX");
  ck_assert_str_eq(addition_operation("M","MM"), "MMM");
  ck_assert_str_eq(addition_operation("III","IV"), "VII");
  ck_assert_str_eq(addition_operation("V","IV"), "IX");
  ck_assert_str_eq(addition_operation("X","II"), "XII");
  ck_assert_str_eq(addition_operation("VIII","X"), "XVIII");
  ck_assert_str_eq(addition_operation("D","D"), "M");
  
  //Test cases for subtraction operation
  ck_assert_str_eq(subtraction_operation("M","C"), "CM");
  ck_assert_str_eq(subtraction_operation("MM","M"), "M");
  ck_assert_str_eq(subtraction_operation("CM","DCCC"), "C");
  ck_assert_str_eq(subtraction_operation("DCC","CD"), "CCC");
  ck_assert_str_eq(subtraction_operation("M","CCC"), "DCC");
  ck_assert_str_eq(subtraction_operation("CI","C"), "I");
  ck_assert_str_eq(subtraction_operation("CXCIX","C"), "XCIX");
  ck_assert_str_eq(subtraction_operation("XLIX","XL"), "IX");
  ck_assert_str_eq(subtraction_operation("XXX","XX"), "X");
  ck_assert_str_eq(subtraction_operation("XIX","X"), "IX");
  ck_assert_str_eq(subtraction_operation("XVIII","X"), "VIII");
  ck_assert_str_eq(subtraction_operation("L","XLIX"), "I");
  ck_assert_str_eq(subtraction_operation("MMXV","MMXIV"), "I");
  ck_assert_str_eq(subtraction_operation("X","VI"), "IV");
  ck_assert_str_eq(subtraction_operation("XC","LXXX"), "X");
  ck_assert_str_eq(subtraction_operation("XLVIII","XL"), "VIII");
  ck_assert_str_eq(subtraction_operation("XVIII","XVII"), "I");
  
  //Test cases for validating user input
  ck_assert_str_eq(addition_operation("q","w"), ""); 
  ck_assert_str_eq(subtraction_operation("S","T"), ""); 
  ck_assert_str_eq(addition_operation("K","J"), ""); 
  ck_assert_str_eq(subtraction_operation("f","q"), ""); 
  ck_assert_str_eq(addition_operation("a","z"), ""); 
  ck_assert_str_eq(subtraction_operation("x","x"), ""); 
  ck_assert_str_eq(addition_operation("i","i"), ""); 
  ck_assert_str_eq(subtraction_operation("c","l"), ""); 
  ck_assert_str_eq(addition_operation("m","v"), ""); 
  ck_assert_str_eq(subtraction_operation("vi","xi"), ""); 
  ck_assert_str_eq(addition_operation("lc","df"), ""); 
  ck_assert_str_eq(subtraction_operation("v","z"), "");
  ck_assert_str_eq(subtraction_operation("CCC","CD"), ""); 
  ck_assert_str_eq(subtraction_operation("DCC","DCCC"), "");
  ck_assert_str_eq(subtraction_operation("CM","M"), "");
  ck_assert_str_eq(subtraction_operation("D","M"), "");

}END_TEST

START_TEST(test_subtract_operation)
{

}END_TEST

START_TEST(test_addition_operation)
{

}END_TEST

Suite *calculator_suite(void) 
{
  Suite *s;
  TCase *tc_core;
  TCase *tc_limits;

  s = suite_create("Roman_Calculator");
 
  /* Core test case */ 
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_core);
  suite_add_tcase(s, tc_core);
  
  /* Limits test case */
  tc_limits = tcase_create("Limits");
  tcase_add_test(tc_limits, test_addition_operation);
  tcase_add_test(tc_limits, test_subtract_operation);
  suite_add_tcase(s, tc_limits);
  
  return s;
}

int main(void) {
  
  int no_failed = 0;
  Suite *s;
  SRunner *runner;

  s = calculator_suite();
  runner = srunner_create(s);
  
  srunner_set_log (runner, "calculator_test.log");

  srunner_run_all(runner, CK_VERBOSE);
  no_failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

