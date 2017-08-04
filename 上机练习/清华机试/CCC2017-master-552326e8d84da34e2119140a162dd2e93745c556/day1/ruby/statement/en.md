{{ self.title() }}

## Problem Statement

There are $n$ cities in the Ruby Land, numbered from $1$ to $n$. $k$ out of these $n$ cities are splendid. Each splendid city has a ruby with its own value.
The king of the Ruby Land, living in city $1$, wants to collect some of these rubies.
For any two different cities $u$ and $v$, there is a one-way road, and it costs the king $c_{u,v}$ to move from $u$ to $v$. The king can move through the same road multiple times if necessary, and he must pay multiple times if he does so.
As soon as the king reaches one city, he could collect the ruby in that city. He can only get the ruby once he visits the city for the first time. For subsequent visits, he will get nothing.
Your task is to find out a sequence of the cities to visit for the king, to get profit as high as possible. The profit is the total value of the rubies collected, minus the total cost of travelling.

## Input Format

{{ self.input_file() }}

The first line contains two non-negative integers $n$ and $k$, where $n$ is the number of the cities and $k$ is the number of the splendid cities.

Each of the following $n$ lines contains $n$ non-negative integers. The $j$-th integer on the $i$-th line among these lines is $c_{i,j}$, which represents the cost for the king to move from city $i$ to city $j$. Please ignore $c_{i,i}$ for $1 \le i \le n$, since those numbers will not be used and are always given as $0$. Please be noticed that $c_{i,j}$ and $c_{j,i}$ could be different, since the cost matrix is not symmetric.

After that, each of the following $k$ lines describes a ruby. Each line contains two non-negative integers $t_r$ and $v_r$, denoting that a ruby valued $v_r$ is in city $t_r$. It is ensured that $1 \le t_r \le n$ for $1 \le r \le k$, and any two of them are different.

There is exactly one space between any two adjacent integers in one line and there are no extra spaces at the end of a line. Each integer in the input is non-negative and no larger than $10^9$. Since the input files are given, you can explore them manually for more information.

At the end of the input file, there is one line contains $8$ integers $s_2, s_3, s_4, \dots, s_9$ which will be explained in *Scoring*.

## Output Format

{{ self.output_file() }}

You should submit an output file for each input file. In each output file, you can write no more than $n^2$ integers, separated by blanks (spaces, tabs, and newlines). These integers represent the sequence of the cities the king visits. Every two adjacent cities $u$ and $v$ in this sequence indicate that the king move from $u$ to $v$ through the one-way road between them, and will cost him $c_{u,v}$.

The king must start his trip from city $1$, so your sequence must start with $1$ as well. He could end his trip at any city around the land.

You don't need to write the profit or which rubies to collect. It is assumed the king will collect the ruby at the first time he reaches a splendid city.

Please be noticed that it may be unnecessary to collect all of the rubies to get a better profit.

{% set vars = {} -%}
{{ self.sample_text() }}

{{ self.title_sample_description() }}

The summary of the profit of this case is ${{ tools.hn(tools.max(prob.down[0].args['ans'])) }}$. Note that city $3$ is visited twice, which is allowed. The king doesn't need to get the ruby in city $2$ since he would cost more than the ruby valued if he does so.

## How to Check Your Output File

You can download a tool named `checker` to check whether the format of your output is correct and get the profit you achieved. Use `checker` as follows:

```
./checker FILE_NAME
./checker INPUT_FILE_NAME OUTPUT_FILE_NAME
```

When `checker` is called by the form on the first line, the input file will be `FILE_NAME.in` and the output file will be `FILE_NAME.out`. If it is called by the form on the second line, the input file will be `INPUT_FILE_NAME`, and the output file will be `OUTPUT_FILE_NAME`.

If your output format is correct, the checker will print the profit. Otherwise the checker will print the error infomation.

You should not use an input file modified by yourself as the input file to the checker. Doing this may break the normal evaluation process.

## Scoring

For any output file, if the file does not exist or the format is not accepted, you get $0$ scores. Otherwise you can get at least $1$ score for this output file.

Let $p_s$ be our best profit and $p_u$ be your profit, your score is given by:

{{ render("table('scoring')") }}

\* $i$ is an integer and $2 \le i \le 8$ in this table.
