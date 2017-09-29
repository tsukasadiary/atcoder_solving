### Getting Difference

数の集合 A = {A_1, A_2, ..., A_N} に対して以下の操作を繰り返す.
* 2つの数 A_i, A_j を選び A に |A_i - A_j| を加える.
このとき， A に K を加えることができるか否か.

### 解法メモ

以下の2つを満たせば良い.
* M = max(A) として， K <= M である.
* A の数すべてのGCDを G としたとき， K が G の倍数である.

必要条件 : どの2つの数を選んで新たな数を加えても， A の数すべてのGCDは G で変化しない.
十分条件 : ユークリッドの互除法と同様の手続きで必ず G を得られる.すると， M と G の差を取る続けることで， M 以下の G の倍数すべてが生成される.