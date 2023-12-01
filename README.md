<h1>11_30 과제</h1>


###  분석내용
- **선택 정렬**,  **삽입 정렬**, **버블 정렬** <br />
  **💻분석**</br> 
        📌 **평균적비교횟수(오름차순)** : 선택 정렬 -> 버블 정렬 -> 삽입 정렬<br/>
        📌 **평균적비교횟수(오름차순)** : 버블 정렬 -> 삽입 정렬 -> 선택 정렬<br/>
  </br>
- **셸 정렬** <br />
  **💻분석**</br>
  📌 **평균적비교횟수** :80~100<br/>
  📌 **평균적비교횟수** :60<br/>
- **합병 정렬** <br />
    합병 정렬의 하나의 리스트를 두 개의 균등한 크기로 분할하고 분할된 부분 리스트를 정렬한 다음, 두 개의 정렬된 부분 리스트를 합하여 전체가 정렬된 리스트가 되게 하는 방법이다.
    <br/>
  📌**Divide(분할) -> Merging(정복) -> Conquer(결합) 하는 방식**<br/><br/>
  **💻분석**<br/>
    합병 정별은 두개의 크기로 분할하기 떄문에 평균적 비교횟수는 퀵 정렬보다 적으나 , 비교횟수는 많은걸 볼수있다.

- **퀵 정렬** <br />
    퀵 정렬은 합병 정렬과 동일한 방식으로 정렬이 돌아간다. 하지만 합병 정렬과 다른점은 입력 배열을 피벗을 기준으로 비균등하게 2개의 부분 배열(피벗을 중심으로 왼쪽: 피벗보다 작은 요소들, 오른쪽: 피벗보다 큰 요소들)로 분할하는 방식이다.
    <br/>
    퀵 정렬은** 2가지 방법으로 진행이 된다. 피봇을 (랜덤 , 중간값)으로 기준점을 잡는방식이다.
    
    **💻분석**</br>
    저는 퀵정렬 20개의 난수로 20번 돌려보았을때 피봇을 평균적 이동횟수와 평균적 비교를 분석해보았다.
    다른 정렬과 다르게 비교적 이동횟수나 평균적 비교횟수들이 적은걸 볼수있다.

<img src="./img/Quick_Sort.png" />
