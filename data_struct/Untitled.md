

## 21合并两个有序链表

最初的想法是用List1为主链，遍历list2里能插入的就插入到list1中，但是后来发现判断条件难以插入list1的末尾。

调试了一段时间选择切换，选用迭代，时间复杂度为O(n+m)（迭代更加容易理解点。

后来看官方题解有更骚的递归（更简单）



## 35搜索插入位置

在这里补充一个小细节，我只在写 Java 代码的时候这样用。

```java
int mid = left + (right - left) / 2;            
```

还可以写成：

```java
int mid = (left + right) >>> 1;
```

这是参考 Java 的 JDK 中 `Arrays.binarySearch()` 函数的写法。理由是 `left + right` 即使是在整型溢出以后，由于无符号右移 `>>> 1` ，仍然能够得到正确的结果（我掌握的语言中，只有 Java 语言中有 `>>>` 这个操作符）。

虽然 `>> 1` 和 `/2` ，但是有些语言编译器都会将 `/2` 转换成位运算的操作，这是编译器内部的优化。因此我们没有必要手动去做这一步优化，写代码的时候还是写 `/ 2`。



## 387字符串中的第一个唯一字符

```java
public int firstUniqChar(String s) {
//这个是我用hashMap的解法，但是算法本身并不太理想
//		Map<Character,Integer> map=new HashMap<Character,Integer>();
//		for (int x = 0; x < s.length(); x++) {
//				char c=s.charAt(x);
//				map.put(c,map.getOrDefault(c,0)+1);
//			}
//		for (int x = 0; x < s.length(); x++) {
//			if(map.get(s.charAt(x))==1)return x;
//		}
//		return -1;

		//leetcode官方题解

		Map<Character, Integer> position = new HashMap<Character, Integer>();
		int n = s.length();
		for (int i = 0; i < n; ++i) {
			char ch = s.charAt(i);
			if (position.containsKey(ch)) {
				position.put(ch, -1);
			} else {
				position.put(ch, i);
			}
		}
		int first = n;
		for (Map.Entry<Character, Integer> entry : position.entrySet()) {
			//entry更像是每一个key个体，for each遍历一个keySet，键值集合
			int pos = entry.getValue();
			if (pos != -1 && pos < first) {
				first = pos;
			}
		}
		if (first == n) {
			first = -1;
		}
		return first;

    }
```

## 144.二叉树的前序遍历





## 876.链表的中间结点



