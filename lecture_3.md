---
layout: page
permalink: /lecture_3/
<!-- title: 수치 자료형과 연산자 -->
description: "수치 자료형과 연산자 소개 및 예제"
tags: [Jekyll, theme, install, setup]
image:
  feature: lecture_3_logo.jpg

share: true
---
  <!--
  credit: dargadgetz
  creditlink: http://www.dargadgetz.com/ios-7-abstract-wallpaper-pack-for-iphone-5-and-ipod-touch-retina/-->


수정2

***
***
# 3. 수치 자료형과 연산자
***
***

***
## 01 수치 자료형
***

### 1-1 정수형 상수

{% highlight html linenos %}
{% raw %}
a = 23      # 10진 정수
b = 023     # 8진 정수
c = 0x23    # 16진 정수
print type(a), type(b), type(c)
print a, b, c
{% endraw %}
{% endhighlight %}


{% highlight html %}
<type 'int'> <type 'int'> <type 'int'>
23 19 35
{% endhighlight %}

####1-2 실수형 상수

{% highlight html linenos %}
{% raw %}
a = 1.2
b = 3.5e3
c = -0.2e-4
print type(a), type(b), type(c)
print a, b, c
{% endraw %}
{% endhighlight %}

{% highlight html %}
<type 'float'> <type 'float'> <type 'float'>
1.2 3500.0 -2e-05
{% endhighlight %}

####1-3 Decimal 자료형
- 컴퓨터의 부동소수점 (Floating point)에 의한 실수 표현은 매우 미미한 오차를 동반함
- 그러한 오차를 최대한 줄이고 최대한 정확한 결과 값을 얻어내기 위해 사용할 수 있는 모듈 -> decimal 모듈
- 다음 두 개의 클래스를 제공
  - Decimal: 숫자 자체를 표현
  - Context: 정확도나 반올림 방법 등과 같은 환경 설정

{% highlight html linenos %}
{% raw %}
e = 0.0                   # 기본 자료형인 float형 변수 e 생성 및 0.0 값으로 초기화
for k in range(10000):    # 0부터 9999 까지 만번 반복
    e += 0.0001           # 0.0001을 누적  
    
print e                   # print로는 1.0이 출력됨
e
{% endraw %}
{% endhighlight %}

{% highlight html %}
1.0
0.9999999999999062
{% endhighlight %}

{% highlight html linenos %}
{% raw %}
from decimal import *
e2 = Decimal('0.0')        # 기본 자료형인 float형 변수 e 생성 및 0.0 값으로 초기화
delta = Decimal('0.0001') # 누적하려고 하는 0.0001 값을 Decimal 객체인 delta 변수로 생성

for k in range(10000):    # 0부터 9999 까지 만번 반복
    e2 += delta            # delta를 누적  
    
print e2                   # print로는 1.0이 출력됨
e2
{% endraw %}
{% endhighlight %}

{% highlight html %}
1.0000
Decimal('1.0000')
{% endhighlight %}

- 최근 python 버전에서는 실수에 대한 지수승 지원 (decimal이 아니어도 실수에 대한 지수승 가능) 
- Decimal 타입과 기본 실수형에 대한 사칙연산은 에러 발생

{% highlight html linenos %}
{% raw %}
a = Decimal('35.72') b = Decimal('1.73')
print a ** 2
a ** b
{% endraw %}
{% endhighlight %}

{% highlight html %}
1275.9184
Decimal('485.8887109649886451686600498')
{% endhighlight %}

- ROUND_HALF_UP vs. ROUND_HALF_EVEN
  - ROUND_HALF_UP:
    - 2.44 -> 2.4
    - ***2.45 -> 2.5***
    - 2.46 -> 2.5
    - ...
    - 2.54 -> 2.5
    - ***2.55 -> 2.6***
    - 2.56 -> 2.6
  - ROUND_HALF_EVEN은 거리가 같은 경우에 마지막의 숫자가 짝수를 유지하도록 함
  - ROUND_HALF_EVEN:
    - 2.44 -> 2.4
    - ***2.45 -> 2.4***
    - 2.46 -> 2.5
    - ...
    - 2.54 -> 2.5
    - ***2.55 -> 2.6***
    - 2.56 -> 2.6

- Rounding에 대한 참고자료
  - https://docs.python.org/2/library/decimal.html#context-objects
  - http://www-01.ibm.com/support/knowledgecenter/SSEPGG_9.7.0/com.ibm.db2.luw.admin.config.doc/doc/r0052298.html?cp=SSEPGG_9.7.0%2F2-2-6-7-29&lang=ko


***
## 02 파이썬 연산자
***

### 2-1 산술 연산자
| 연산자 |    우선순위  | 설명   | 결합순서 |
|:------:|:------:|:-----------------:|:-----------:|
| +, -     |    1   |   단항 연산자        |  -  | 
|  **      |    2   |지수 연산자        | 왼쪽 <- 오른쪽 | 
| *,/,%,// |    3    |곱하기,나누기,나머지,몫 | 왼쪽 -> 오른쪽 | 
| +, -     |    4    |더하기,빼기           |   왼쪽 -> 오른쪽  |

{% highlight html linenos %}
{% raw %}
print 2 ** 3
print 5 % -3
print 3.0 // 4.0
print -3 // 4
print 3.0 / 4.0
print -3 / 4
print -7/4     #단항 연산자(-)의 우선순위가 이항 연산자(/)의 우선순위보다 높다 (-7을 4로 나눈다).
print -(7/4)   #7/4의 결과에 단항 연산을 수행함
print 2 + 3 * 4
print --3
{% endraw %}
{% endhighlight %}

{% highlight html %}
8
-1
0.0
-1
0.75
-1
-2
-1
14
3
{% endhighlight %}

### 2-2 관계 연산자
- 객체가 지닌 값의 크기(대소)를 비교함

{% highlight html linenos %}
{% raw %}
print 6 == 9
print 6 != 9

a = 5
b = 10
0 < a and a < b
{% endraw %}
{% endhighlight %}

{% highlight html %}
False
True

True
{% endhighlight %}

- 서로 다른 자료형간의 크기 관계
  - 숫자 < 사전 < 리스트 < 문자열 < 튜플

### 2-3 논리 연산자 (or 부울 연산자)
- 피연산자의 값으로 진리값인 True 또는 False을 취하여 논리 적인 계산을 수행하는 연산자
  - and
  - or
  - not
- 논리 연산자 자체가 값을 반환하지는 않는다. 
- 논리 연산을 따라 최종적으로 평가(Evaluation)되어진 값이 반환된다.

{% highlight html linenos %}
{% raw %}
a = 20
b = 30

a > 10 and b < 50
{% endraw %}
{% endhighlight %}

{% highlight html %}
True
{% endhighlight %}

- 진리값에 해당하는 True와 False는 다른 사칙연산자를 만나면 다음과 같이 평가됨
  - True: 1
  - False: 0

{% highlight html linenos %}
{% raw %}
print True + 1
print False + 1

print bool(0) # 정수 0은 거짓
print bool(1)
{% endraw %}
{% endhighlight %}

{% highlight html %}
2
1

False
True
{% endhighlight %}

- 값이 없는 빈 객체나 None 객체는 False로 평가됨

### 2-4 비트 단위 연산자
- 비트 단위 조작 지원
- 비트 단위 연산자
 - ~ : 비트 반전 (보수)
 - &lt;&lt;: 왼쪽으로 비트 이동
 - &gt;&gt;: 오른쪽으로 비트 이동
 - & :  비트 단위 AND
 - ^ : 비트 단위 XOR
 - | : 비트 단위 OR

#### 참고: 음수의 표현 (2의 보수 표현법)
- 음수는 leading one 으로 시작함 (양수는 leading zero)
- 만약 정수가 8비트로 이루진다면 "0000 0000"에서 "0111 1111" 숫자는 0에서 127을 나타냄
- 만약 정수가 8비트로 이루진다면 "1000 0000"에서 "1111 1111" 숫자는 -128에서 -1을 나타냄
  - ***[약속] 음수인 -x는 (x - 1)에 대한 1의 보수로 표현 (2의 보수 표현법)***
    - -x = 1's complement of (x - 1)
  - -1 = (1 - 1)에 대한 1의 보수 = 0에 대한 1의 보수 = "0000 0000"에 대한 1의 보수 = "1111 1111"
  - -10 = (10 - 1)에 대한 1의 보수 = 9에 대한 1의 보수 = "0000 1001"에 대한 1의 보수 = "1111 0110" 
  - -128 = (128 - 1)에 대한 1의 보수 = 127에 대한 1의 보수 = "0111 1111"에 대한 1의 보수 = "1000 0000"
  - "1111 1010" = "0000 0101"에 대한 1의 보수 = 5에 대한 1의 보수 = (6 - 1)에 대한 1의 보수 = -6
  - "1111 1110" = "0000 0001"에 대한 1의 보수 = 1에 대한 1의 보수 = (2 - 1)에 대한 1의 보수 = -2
- 참고
  - http://www.ecogwiki.com/2%EC%9D%98_%EB%B3%B4%EC%88%98%EB%B2%95%EC%9C%BC%EB%A1%9C_%EC%9D%8C%EC%88%98_%ED%91%9C%ED%98%84%ED%95%98%EA%B8%B0
  - http://multithread.tistory.com/entry/%EC%A0%95%EC%88%98%EC%9D%98-2%EC%9D%98%EB%B3%B4%EC%88%98-%ED%91%9C%ED%98%84



<!-- 댓글 기능 -->
<html>
<body>
<a href="http://foo.com/bar.html#disqus_thread">Link</a>.

    <div id="disqus_thread"></div>
    <script type="text/javascript">
        var disqus_shortname = 'slhblog';
        (function() {
            var dsq = document.createElement('script'); dsq.type = 'text/javascript'; dsq.async = true;
            dsq.src = '//' + disqus_shortname + '.disqus.com/embed.js';
            (document.getElementsByTagName('head')[0] || document.getElementsByTagName('body')[0]).appendChild(dsq);
        })();
    </script>
    <noscript>Please enable JavaScript to view the <a href="http://disqus.com/?ref_noscript">comments powered by Disqus.</a></noscript>

</body>
</html>

<!-- 이미지 기능 -->
<figure>
	<a href="http://farm9.staticflickr.com/8426/7758832526_cc8f681e48_b.jpg"><img src="http://farm9.staticflickr.com/8426/7758832526_cc8f681e48_c.jpg" alt=""></a>
	<figcaption><a href="http://www.flickr.com/photos/80901381@N04/7758832526/" title="Morning Fog Emerging From Trees by A Guy Taking Pictures, on Flickr">Morning Fog Emerging From Trees by A Guy Taking Pictures, on Flickr</a>.</figcaption>
</figure>

<!-- 동영상 기능 -->
<iframe width="560" height="315" src="//www.youtube.com/embed/SU3kYxJmWuQ" frameborder="0"> </iframe>

<!-- 코드입력부 기능 -->
{% highlight html linenos %}
{% raw %}
def add(a,b):
  return a+b
  
print add(1,2)
{% endraw %}
{% endhighlight %}


<!-- 코드 출력부 기능 -->
{% highlight html %}
<iframe width="560" height="315" src="//www.youtube.com/embed/SU3kYxJmWuQ" frameborder="0"> </iframe>
{% endhighlight %}

<html>

<!-- 문제풀이 -->
<div class="page">
<div class="body">
<div class="main">

<SCRIPT> 
function func(){

 var chk=document.fm.chk_1;
 
 for(i=0;i<chk.length;i++){
  if(chk[i].checked==true){
   if (i == 2 ) {
    //창 뜨게 하는거
    alert('\n\n정답입니다.'+ "\n"); }
   else {
    alert('\n\n틀렸습니다. 정답은 3번, print "Hello, World"'+ "\n"); }
   break;
  }
 }
}
</script>

<form name="fm" method="get">

 <p> 1. "Hello, World를 출력하는 문장으로 옳은 것은? </p>
 
 <p></p>
 <input type="radio" name="chk_1" value="chk_1"> (1) print Hello, World <p></p>
 <input type="radio" name="chk_1" value="chk_2"> (2) printf Hello, World <p></p>
 <input type="radio" name="chk_1" value="chk_3"> (3) print "Hello, World" <p></p>
 
  <p><form name="input" method="post" action="">
  <input type="button" value="확인" onClick="func()"></form></p>

 
 
</div>
</div>
</div>

</html>

<!-- 사지선다형 문제 끝 -->