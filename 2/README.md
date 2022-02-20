T1 DS顺序表–类实现.cpp
T2 DS顺序表–连续操作.cpp
T3 DS顺序表–合并操作.cpp
T4 DS顺序表之循环移位.cpp
T5 计算2支股票的M天运动平均价格.cpp
# T1
```cpp class.cpp
 //以下定义
        //位置是查询的序列号，位序是位置的-1，即数组里面的序列号
		int list_del(int i){//和insert类似
			if(i<=0||i>size){//查询错误情况：没有这个位置
				cout<<"error"<<endl;
				return 0;
			}
			for(int j = i-1; j < size-1 ;j++){//从这个位序开始，直到最后一个位序
				list[j]=list[j+1];//后一个的值赋给前一个
			}
			size--;//大小变小
			list_display();
		}
		int list_insert(int i,int item){
			if(i<0||i>size+1){//查询错误情况：不能增加的位置
				cout<<"error"<<endl;
				return 0;
			}
			for(int j = size; j >i-1 ;j--){//从最后一个的后一个的位序开始，直到这个位序
				list[j]=list[j-1];//前一个赋给后一个
			}// ! 最后一步是p[j]=1,j=1,i=1;先j--，然后判断0>0不通过，跳出循环
			list[i-1]=item;//值赋给这个位序
			size++;//变大
			list_display();
		}
```