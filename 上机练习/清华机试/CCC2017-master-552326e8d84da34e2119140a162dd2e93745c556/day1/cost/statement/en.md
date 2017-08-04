{{ self.title() }}

## Problem Statement

You are moving in a Cartesian plane.  At the beginning you are at $(0, 0)$, and your target is $(n, m)$.
Once you are at $(x, y)$, you can move to the point $(x, y+1)$ with the cost $A_x$, 
or move to the point $(x+1, y)$ with the cost $B_y$.

Given the sequences $A$ and $B$, your task is to find out the minimum cost from $(0, 0)$ to $(n, m)$.

## Input Format

{{ self.input_file() }}

The first line of the input contains two positive integers $n$ and $m$.

The second line of the input contains $n+1$ positive integers, representing the sequence $\langle A_0, A_1, \dots, A_n \rangle$.

The third line of the input contains $m+1$ positive integers, representing the sequence $\langle B_0, B_1, \dots, B_m \rangle$.

In $30\%$ of the test cases, $n, m \leq 5\,000$;

In another $30\%$ of the test cases, $B_j = j$ for $0 \leq j \leq m$.

In $100\%$ of the test cases, $n, m \leq 500\,000$, $A_i, B_i \leq 1\,000\,000\,000$;


## Output Format

{{ self.output_file() }}

The output only contains one integer, representing the minimum cost.

{% set vars = {} -%}
{%- do vars.__setitem__('sample_id', 1) -%}
{{ self.sample_text() }}

{%- do vars.__setitem__('sample_id', 2) -%}
{{ self.sample_text() }}
