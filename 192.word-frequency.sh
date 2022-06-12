#
# @lc app=leetcode id=192 lang=bash
#
# [192] Word Frequency
#

# @lc code=start
# Read from the file words.txt and output the word frequency list to stdout.
cat words.txt | tr -s ' ' '\n' | sort | uniq -c | sort -r -n -k 1 | awk '{ print $2, $1 }'

# tr -s: truncate the string with target string, but only remaining one instance (e.g. multiple whitespaces)
# sort: To make the same string successive so that uniq could count the same string fully and correctly.
# uniq -c: uniq is used to filter out the repeated lines which are successive, -c means counting
# sort -r: -r -n -k 1 to sort by number DESC and specify the sort column is the first column with word frequncy of uniq -c
# awk '{ print $2, $1 }': To format the output, see https://linux.cn/article-3945-1.html
# @lc code=end

