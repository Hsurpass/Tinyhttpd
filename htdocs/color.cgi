#!/usr/bin/perl -Tw

# 相当于include, 引用这两个库
use strict; 
use CGI;

# 定义一个变量
my($cgi) = new CGI;

print $cgi->header;
# 默认值
my($color) = "blue";
$color = $cgi->param('color') if defined $cgi->param('color');

print $cgi->start_html(-title => uc($color),
                       -BGCOLOR => $color);
print $cgi->h1("This is $color");
print $cgi->end_html;
