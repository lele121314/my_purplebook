{{ self.title() }}

## Problem Statement

The game of Tetris is played with Tetrominoes (four-connected blocks) falling down and a board with $h$ rows and 10 columns.

There are 7 types of Tetrominoes name 'A' to 'G', and each Tetromino can be rotated with 90, 180 or 270 degrees, shown in figure below.

{{ render("template('image', resource = resource('figure3-1.png'), size = 0.5, align = 'middle')") }}

When a Tetromino appear, the player can rotate it and adjust its horizontal position (left or right). 

Then, the Tetromino will falling down until it hits the other block or the bottom of the board.

When a row is filled, it will be removed and the player will get one points.

Now, there are $n$ Tetrominoes falling down. For each Tetromino, you will get the rotating times and the horizontal position supporting by a real player.

Your task is simulating the game and output the score of this player.

## Input Format

{{ self.input_file() }}

The first line of input contains two positive integers $n$ and $h$, representing the number of Tetrominoes and the rows of board.

The next $n$ lines describe the $n$ Tetrominoes, each line contains a char $t$ and two integers $r$, $x$,

where $t$ represents the type of Tetromino, it can be 'A' to 'G',

$r$ is the rotating times ($0 \leq r \leq 3$),

and $x$ is the horizontal position ($0 \leq x \leq 10-w$), $w$ is the width of the Tetromino.

In other words, $x$ is the number of columns that between the Tetromino and the left border of the board.

In 20\% of the test cases, the type of Tetrominoes must be 'A' or 'B'.

In 60\% of the test cases, $n \leq 100$ and $h \leq 50$.

In 80\% of the test cases, $n \leq 2,000$ and $h \leq 5,000$.

In 100\% of the test cases, $n \leq 500,000$ and $h \leq 500,000$.

## Output Format

{{ self.output_file() }}

The output only contains one integer, the score of player.

{% set vars = {} -%}
{%- do vars.__setitem__('sample_id', 1) -%}
{{ self.sample_text() }}

{%- do vars.__setitem__('sample_id', 2) -%}
{{ self.sample_text() }}

{% set vars = {} -%}
{{ self.title_sample_description() }}

The processing of sample 1 is shown in the figure below.

{{ render("template('image', resource = resource('figure3-2.png'), size = 0.5, align = 'middle')") }}

