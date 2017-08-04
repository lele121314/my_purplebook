{% block title %}{% endblock %}


## 【题目描述】

生活在在外星球X上的小Z想要找一些小朋友组成一个舞蹈团，于是他在网上发布了信息，一共有 $n$ 个人报名面试。

**面试必须按照报名的顺序**依次进行。小Z可以选择在面试完若干小朋友以后，在所有**已经面试过**的小朋友中进行任意顺序的挑选，以组合成一个舞蹈团。

虽然说是小朋友，但是外星球X上的生态环境和地球上的不太一样，这些小朋友的身高可能相差很大。小Z希望组建的这个舞蹈团要求**至少**有 $m$ 个小朋友，并且这些小朋友的最高身高和最低身高之差不能超过 $k$ 个长度单位。

现在知道了这些小朋友的身高信息，问小Z至少要面试多少小朋友才能在已经面试过的小朋友中选出不少于 $m$ 个组成舞蹈团。

## 【输入格式】

{% block input_file %}{% endblock %}

第一行 $3$ 个整数 $n,m,k$，意义见题面描述；$1 \le m \le n \le {{tools.hn(prob['args'][0].value)}}; 0 \le k \le {{tools.hn(prob['args'][1].value)}}$；

第二行 $n$ 个整数，第 $i$ 个数 $h_i$ 表示第 $i$ 个报名面试的小朋友的身高， $1 \le h_i \le {{tools.hn(prob['args'][1].value)}}$。

## 【输出格式】

{% block output_file %}{% endblock %}

如果可以选出舞蹈团，输出**至少**要面试多少人；否则输出 `impossible`。

{% set vars = {} -%}
{%- do vars.__setitem__('sample_id', 1) -%}
{{ self.sample_text() }}

{{ self.title_sample_description() }}
{{ down_file('interview1.explain') }}

{% set vars = {} -%}
{%- do vars.__setitem__('sample_id', 2) -%}
{{ self.sample_text() }}

{{ self.title_sample_description() }}
{{ down_file('interview2.explain') }}

{% set vars = {} -%}
{%- do vars.__setitem__('sample_id', 3) -%}
{{ self.sample_text() }}

{% set vars = {} -%}
{% do vars.__setitem__('sample_id', 4) -%}
{{ self.sample_file() }}

## 【子任务】

**本题目一共 $20$ 个测试点，所有测试点均不开启O2优化。**

{{ render("table('data')") }}
