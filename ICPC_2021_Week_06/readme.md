# 2017-2018 ACM-ICPC, Central Europe Regional Contest (CERC 17)
## Tổng quan
|[A](#a)|[B](#b)|[C](#c)|[D](#d)|[E](#e)|[F](#f)|[G](#g)|[H](#h)|[I](#i)|[J](#j)|[K](#k)|[L](#l)|
|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|
|  SOL  |  N/A  |  N/A  |  N/A  |  N/A  |  SOL  |  N/A  |  SOL  |  N/A  |  N/A  |  N/A  |  N/A  |

Ký hiệu: 
1. `N/A`: Not attempted
2. `SOL`: Solved within the contest time
3. `SWH`: Solved with hint (from tutorial, solutions,... or from any external material), in the contest time
4. `UPS`: Upsolved - solved after the contest
5. `NAC`: Not accepted - failed during contest, not yet upsolved

## Cụ thể
### A
[Link to submission](A/data.cpp)

Chỉ cần implement và rất cẩn thận điều kiện. Có thể cày trâu các phần như tìm kiếm, check nếu máy bay balance để tiết kiệm thời gian code.


### B
[Link to submission](B/data.cpp)


### C
[Link to submission](C/data.cpp)


### D
[Link to submission](D/data.cpp)


### E
[Link to submission](E/data.cpp)


### F
[Link to submission](F/data.cpp)

Chia trường hợp. Để ý nếu:
- n lớn hơn hoặc bằng 2*p, thì n! sẽ có hai thừa số nguyên tố p, nên số dư %p luôn bằng 0.
- Ngược lại nhưng n lớn hơn hoặc bằng p, trừ trường hợp n=p=2 là -1, nếu r=0 luôn có thể làm được. Nếu r!=0, chỉ cần cày trâu vị trí p (vì nó phải khác p để có số dư khác 0).
- Ngược lại, xét biểu thức `n!/i*x = r (mod p)` với `i` và `x` vị trí và giá trị làm Factorial này "Faulty".
Ta có thể chuyển `n!` và `i` qua kia => `x = r*i * n!^-1` (số inverse), có thể giải được x. Sau đó, xét nếu x nằm
trong [1, i). Tính trước n!^-1 và cày trâu vị trí i trong O(n)


### G
[Link to submission](G/data.cpp)


### H
[Link to submission](H/data.cpp)

Code tay to... 
* Xây dựng một cái cây (struct Node* như trong C++), Node chứa một list tới các Node khác
chính là các sub dir của thư mục đó. Đầu tiên cứ cố xây dựng một cái cây thư mục.
* Tính size thì cộng lên khi đang đệ quy xây dựng cây.
* Sau đó:
    - Mỗi thư mục có dấu + nếu như tất cả thư mục con của nó có size < hơn t.
	- Mỗi thư mục có dấu - nếu tồn tại 1 thư mục con có size >= t.
	- Dấu ' ' nếu không có thư mục con


### I
[Link to submission](I/data.cpp)


### J
[Link to submission](J/data.cpp)


### K
[Link to submission](K/data.cpp)


### L
[Link to submission](L/data.cpp)


