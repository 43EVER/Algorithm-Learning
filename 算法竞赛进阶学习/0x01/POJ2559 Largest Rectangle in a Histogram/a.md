* 题目
    * 从左到右给一连串的高度为1的矩形
    * 求最大矩形面积

* 用单调栈做，维护一个栈，高度递增
    * 对于每个高度
        * 大于栈顶 直接入栈
        * 小于等于栈顶

        ``` cpp
        int width = 0;
        while (s.size() && x < s.top().height) {
            width += s.top().width;
            ans = max(ans, width * s.top().height);
            s.pop();
        }
        s.push({x, width + 1});
        ```

* 防止栈里面还用东西，最后往里塞个0，同样根据以上策略

* 时间复杂度
    * 每个矩形都会出栈一次 O(N)