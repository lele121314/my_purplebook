{{ self.title() }}

## Problem Statement

Given a sentence $s$ made up of $n$ words $w_1, w_2, \dots, w_n$, your task is to reverse the order of those words and output $w_n, w_{n-1}, \dots, w_1$.

For example, the sentence is `i like eating apple`, you need to output `apple eating like i`.

## Input Format

{{ self.input_file() }}

The input contains a string $s$, which only contains lower-case letters and spaces.

In $20\%$ of the test cases, each word only contains one letter.

In another $20\%$ of the test cases, the sentence only contains one space.

In $100\%$ of the test cases, $|s| \leq 200$.

## Output Format

{{ self.output_file() }}

The output only contains one line, representing the reversed sentence.

{% set vars = {} -%}
{%- do vars.__setitem__('show space', True) -%}
{%- do vars.__setitem__('sample_id', 1) -%}
{{ self.sample_text() }}

{%- do vars.__setitem__('sample_id', 2) -%}
{{ self.sample_text() }}

{% set vars = {} -%}

{{ self.title_sample_description() }}

You should pay attention to the empty strings.

{{ render(''' "
Please be noticed that blanks between any pair of words in the output should be kept as in the input.  The spaces are rendered in an explicit way in the above sample inputs and outputs.
" ''', 'tex') }}
