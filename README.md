Duyệt đồ thị/tìm cây bằng BFS, DFS trên đồ thị.

I. Phần input sẽ để ở "INPUT.txt", định dạng input như sau:
1. Dòng đầu chứa 2 số nguyên n,m (0 < n < ???, 0 <= m <= C^2_n).
2. m dòng sau, mỗi dòng 2 chứa 2 số nguyên phân biệt x,y cách nhau bởi dấu cách (0<= x,y <= n-1) biểu diễn cạnh x->y.

II. Phần output gồm 2 dòng:
1. Dòng 1: DFS : thứ tự duyệt đỉnh của đồ thị bằng DFS (thứ tự từ trái qua phải).
2. Dòng 2: BFS : thứ tự duyệt đỉnh của đồ thị bằng BFS (thứ tự từ trái qua phải).

Ở đây mình làm ví dụ trên đồ thị vô hướng , nếu là đồ thị có hướng thì đã có note trong phần code.
Ví dụ với đồ thị này:

<p align="center">
  <img src="Graph.png" alt="Graph" width="500"/>
</p>

Ở đây sau khi chạy code ta sẽ được:

DFS: 0 3 6 1 5 9 2 7 4 8

BFS: 0 3 4 5 7 6 9 8 1 2

Tất nhiên sẽ theo thứ tự đầu vào của input, cạnh nào vào trước thì đỉnh kề ấy sẽ vào trước và khi duyệt sẽ được duyệt trước.

Hết.
