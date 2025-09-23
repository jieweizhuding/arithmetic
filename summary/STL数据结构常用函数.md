## vector
```C++
vector<int> v(size,pre_value);
v.push_back();
v.pop_back();
```
更多函数见[菜鸟教程-vector](https://www.runoob.com/cplusplus/cpp-libs-vector.html)

## unordered_map
```C++ 
//unordered_map与unordered_set都是底层默认使用hash实现，可以用于去重

unordered_map<int,int> hash;
hash.insert({key,value});
hash.erase(key);

for(const auto& pair: hash){
  coit<<pair.first<<" "<<pair.second<<endl;
}

if(hash.find(key)!=hash.end()){
  cout<<hash[key];
}else{
  hash[key]++;
}
```

## priority_queue
```C++
//使用堆实现

static bool cmp(const pair<int,int> &a,const pair<int,int>& b){
  return a.second>b.second;
}
priority_queue<int,vector<int>,decltype(&cmp)> min_heap(cmp);
priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(&cmp)> min_heap(cmp);
min_heap.push({a,b});
min_heap.pop();
min_heap.top();
```
