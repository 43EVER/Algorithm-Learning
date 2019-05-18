* 两个stack存cursor前后字符
* sum[] 保存前缀
* max_sum[] 保存某个位置的最大前缀和

* 插入时，顺便更新sum 与 max_sum
    * sum[pos] = sum[pos - 1] + value;
    * max_sum[pos] = max(max_sum[pos - 1], sum[pos]);
* 删除，左移按题目要求进行即可
* 右移时，更新sum与max_sum
    * before.push(after.top());
    * sum[pos] = sum[pos - 1] + before.top();
    * max_sum[pos] = max(max_sum[pos - 1], sum[pos]);

* 时间复杂度
    * 修改O(1)
    * 查询O(1)