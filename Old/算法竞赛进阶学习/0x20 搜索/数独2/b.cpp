#include <bits/stdc++.h>
using namespace std;
const int N=16;
int ones[1<<N],cnt_log[1<<N];//ones[x]表示x在二进制下有多少个1；log[x]表示log(x)的值 
int state[N][N];//状态存储，表示x行y列这个格子可以填哪些数（0-15），15位二进制表示 
char str[N][N+1];
int bstate[N*N+1][N][N],bstate2[N*N+1][N][N];//bstate和bstate2都存储状态的备份(搜索最多有N*N层，每层有一个备份) 
char bstr[N*N+1][N][N+1];//输入的N宫格也要备份 

inline int lowbit(int x)//返回x在二进制下的最后一个1  (inline加速函数调用过程)
{
    return x & -x;
}

void draw(int x,int y,int c)//在(x,y)这个格子上写上字母c(0到15表示A到P) 
{
    str[x][y]='A'+c;//先写进去，转换为原来的字母 

    for (int i=0;i<N;++i)//更新state 
    {
        state[x][i] &= ~(1 << c);//x这一行其他位置都不能再填c (把表示c的二进制位改成0，yxc大佬的位运算)
        state[i][y] &= ~(1 << c);//y这一列其他位置都不能再填c 
    }

    int sx=x/4*4,sy=y/4*4;//把(x,y)所在的十六宫格也做一次同样的操作 
    for (int i=0;i<4;++i)
        for (int j=0;j<4;++j)
                state[sx+i][sy+j] &= ~(1 << c);//同上 

    state[x][y]=1<<c;
}

bool dfs(int cnt)//传入的参数cnt表示当前空格个数 
{
    if (!cnt) return true;//cnt为零就找到了方案，返回true

    int kcnt=cnt;//先进行备份 
    memcpy(bstate[kcnt],state,sizeof state);
    memcpy(bstr[kcnt],str,sizeof str);

    //剪枝1：对于每个空格，如果不能填任何一个字母，则返回false；如果只能填一个字母，那么直接填上
    for (int i=0;i<N;++i)//直接枚举所有的空格
        for (int j=0;j<N;++j)
            if (str[i][j]=='-')//如果当前格子是空格 
            {
                if (!state[i][j])//如果不能填任何一个字母，则返回false；并且copy回去 
                {
                    memcpy(state,bstate[kcnt],sizeof state);
                    memcpy(str,bstr[kcnt],sizeof str);
                    return false;
                }
                if (ones[state[i][j]]==1)//如果只能填一个字母，那么直接填上
                {
                    draw(i,j,cnt_log[state[i][j]]);
                    --cnt;//填好一个空格，所以剩余空格数减1
                }
            }

    //剪枝2：对于每一行，如果某个字母不能出现在任何一个位置，则返回false；如果某个字母只有一个位置可以填，则直接填上 
    for (int i=0;i<N;++i)//枚举所有行 
    {
        int sor=0,sand=(1<<N)-1;//sor存的是这一行里每个格子备选方案的并集;sand用来找“如果某个字母只有一个位置可以填”，先假设所有字母都符合要求 
        int drawn=0;//drawn表示所有已经填上的字母是哪些 

        for (int j=0;j<N;++j)//枚举当前行所有格子 
        {
            int s=state[i][j];//只是为了少打字 
            sand &= ~(sor & s);//把不符合要求的删掉(和前面更新state是一个道理) 
            sor |= s;//求并集 
            if (str[i][j]!='-') drawn |= state[i][j];//如果当前这个位置已经填上字母，就记录下来 
        }

        if (sor!=(1<<N)-1)//如果这个并集不够A到P就是无解 
        {
            memcpy(state,bstate[kcnt],sizeof state);//同上述处理方法 
            memcpy(str,bstr[kcnt],sizeof str);
            return false;
        }

        //这样以后sand中是1的位置就表示这个字母有一个位置可以填
        for (int j=sand;j;j-=lowbit(j))//所以把所有是1的位置枚举一遍 
        {
            int t=lowbit(j);//也是为了少写一点 
            if (!(drawn & t))//如果正好也没填过就填上 
            {
                for (int k=0;k<N;++k)//更新state 
                    if (state[i][k] & t)
                    {
                        draw(i,k,cnt_log[t]);
                        --cnt;
                        break;
                    }
            }
        }
    }

    //剪枝3：对于每一列，同剪枝2  (直接把上面复制过来再把i和j调换一下就好了) 
    for (int i=0;i<N;++i)
    {
        int sor=0,sand=(1<<N)-1;
        int drawn=0;

        for (int j=0;j<N;++j)
        {
            int s=state[j][i];
            sand &= ~(sor & s);
            sor |= s;
            if (str[j][i]!='-') drawn |= state[j][i];
        }

        if (sor!=(1<<N)-1)
        {
            memcpy(state,bstate[kcnt],sizeof state);
            memcpy(str,bstr[kcnt],sizeof str);
            return false;
        }

        for (int j=sand;j;j-=lowbit(j))
        {
            int t=lowbit(j);
            if (!(drawn & t))
            {
                for (int k=0;k<N;++k)
                    if (state[k][i] & t)//这里i和k也要和上面要反一下 
                    {
                        draw(k,i,cnt_log[t]);
                        --cnt;
                        break;
                    }
            }
        }
    }

    //剪枝4：对于每个N宫格，同剪枝2
    for (int i=0;i<N;++i)//i枚举每个N宫格的位置 
    {
        int sor=0,sand=(1<<N)-1;
        int drawn=0;

        for (int j=0;j<N;++j)//j枚举一个N宫格的每个位置 
        {
            int sx=i/4*4,sy=i%4*4;
            int dx=j/4,dy=j%4;//需要定义一个偏移量 
            int s=state[sx+dx][sy+dy];
            sand &= ~(sor & s);
            sor |= s;

            if (str[sx+dx][sy+dy]!='-') drawn |= state[sx+dx][sy+dy];
        }

        if (sor!=(1<<N)-1)
        {
            memcpy(state,bstate[kcnt],sizeof state);
            memcpy(str,bstr[kcnt],sizeof str);
            return false;
        }

        for (int j=sand;j;j-=lowbit(j))
        {
            int t=lowbit(j);
            if (!(drawn & t))
            {
                for (int k=0;k<N;++k)
                {
                    int sx=i/4*4,sy=i%4*4;
                    int dx=k/4,dy=k%4;
                    if (state[sx+dx][sy+dy] & t)
                    {
                        draw(sx+dx,sy+dy,cnt_log[t]);
                        --cnt;
                        break;
                    }
                }
            }
        }
    }
    //啊，还剩一个剪枝啦 

    //剪枝5：每次选择空格时，选择备选方案(能填的字母数量)最少的格子来填 
    if (!cnt) return true;//哦对，先看看现在有没有填完(一个小剪枝) 

    int x,y,s=100;//(x,y)存储最后选择的格子，s是备选方案最小值 
    for (int i=0;i<N;++i)//遍历一遍所有的格子 
        for (int j=0;j<N;++j)
            if (str[i][j]=='-' && ones[state[i][j]]<s)//如果当前格子还没填过，并且这个格子的备选方案更少，就更新 
            {
                s=ones[state[i][j]];
                x=i,y=j;
            }

    //求完了那个格子备选方案最少，然后枚举应该在这个格子填那个字母 
    memcpy(bstate2[kcnt],state,sizeof state);//先备份一下，bstate2在这里终于用到了 
    for (int i=state[x][y];i;i-=lowbit(i))//枚举这个格子的备选方案 
    {
        memcpy(state,bstate2[kcnt],sizeof state);
        draw(x,y,cnt_log[lowbit(i)]);
        if (dfs(cnt-1)) return true;//进行下一层递归，如果成功，返回true 
    }

    //失败了也要copy回来 
    memcpy(state,bstate[kcnt],sizeof state);
    memcpy(str,bstr[kcnt],sizeof str);

    return false;//一直没找到返回false 
}

int main()
{
    for (int i=0;i<N;++i) cnt_log[1<<i]=i;//预处理cnt_log数组，如log(2)=1,log(4)=2,log(8)=3 
    for (int i=0;i<(1<<N);++i)//预处理ones数组 
        for (int j=i;j;j-=lowbit(j))//j每次减去最后一个1 
            ++ones[i];//每减一个1说明这个i就多一个1 

    while (cin>>str[0])//多组测试数据 
    {
        for (int i=1;i<N;++i) cin>>str[i];
        for (int i=0;i<N;++i)//预处理state
            for (int j=0;j<N;++j)
                state[i][j]=(1<<N)-1;//一开始假设所有空格都是空的

        int cnt=0;//存储空格个数
        for (int i=0;i<N;++i)//接着在遍历一遍，看那些格子已经填好了
            for (int j=0;j<N;++j)
                if (str[i][j]!='-') draw(i,j,str[i][j]-'A');//如果已经填好了就更新state,A到P分别用0到15表示
                else ++cnt;

        dfs(cnt);//DFS开始

        for (int i=0;i<N;++i) cout<<str[i]<<endl;//输出答案
        puts("");//每次输出完答案加一个空行
    }
    return 0;
}
//终于结束了
//有问题可以留言

作者：Lee2004
链接：https://www.acwing.com/solution/acwing/content/4271/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。