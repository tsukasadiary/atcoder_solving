### Minimum Sum

[1,n] の順列となっている数列 a = (a_1, a_2, ..., a_n) が与えられるので，
sum_{i=1}^{n} sum_{j=i}^{n} min(a_i, a_{i+1}, ..., a_j)
を求めよ.

### 解法メモ

各 i ∈ [1,n] について， a_i の左側および右側で自身未満で最も近いもののインデックスを，それぞれ l_i, r_i と置くと，
sum_{i=1}{n} i * (r_i - i) * (i - l_i)
が答えとなる.

これは，小さい値から順に調べて，そのインデックスを set などで管理する.
すると，ある値 x を調べるとき， set には x 未満の要素のインデックスが入っているため，二分探索などで l_i, r_i に相当するものを計算可能である.