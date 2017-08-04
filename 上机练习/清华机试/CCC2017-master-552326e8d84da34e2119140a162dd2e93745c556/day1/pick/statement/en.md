{{ self.title() }}

## Problem Statement

Given a positive integer $n$, you are picking elements from $\{1, 2, ..., n\}$ under the following rule.

For any two integers $a$ and $b$, you can pick only one of them if they satisfy the equation $\text{lcm}(a, b) / \text{gcd}(a, b) = c^2$, where $c^2$ is a square number, and $\text{gcd}(a, b)$ and $\text{lcm}(a, b)$ are the greatest common divisor and least common multiple for two integers $a$ and $b$, respectively.

Your task is to pick as many integers as possible and output the size of the picked subset.

## Input Format

{{ self.input_file() }}

The input only contains an positive integer $n$.

In $40\%$ of the test cases, $n \leq 20$;

In $70\%$ of the test cases, $n \leq 40$;

In $90\%$ of the test cases, $n \leq 5\,000$;

In $100\%$ of the test cases, $n \leq 500\,000$;

## Output Format

{{ self.output_file() }}

Just output an integer, which representing the maxinum size of the subset.

{% set vars = {} -%}
{%- do vars.__setitem__('sample_id', 1) -%}
{{ self.sample_text() }}

{%- do vars.__setitem__('sample_id', 2) -%}
{{ self.sample_text() }}

{% set vars = {} -%}
{{ self.title_sample_description() }}

In the second sample, we can pick either $\{1, 2, 3, 5\}$ or $\{2, 3, 4, 5\}$.  Both of the subsets have a size of $4$.
