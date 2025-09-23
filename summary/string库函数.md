#### 分割字符串
```C++
//size_t find(string s,int start):返回从start开始查找的到的第一个s的起始位置的下标，不用start的话，默认为0，没有找到返回string::npos

//string substr(int start,int size):返回从start开始的长度为size的字符串

vector<string> stringsplit(string s,char delimeter){
  vector<string> res;
  size_t start=0,end=s.find(delimeter);
  while(end!=string::npos){
    res.push_back(s.substr(start,end-start));
    start=end+1;
    end=s.find(delimeter,start);
  }
  res.push_back(s.substr(start));
}

```

#### 字符串转数字
```C++
int i=stoi(s);
```