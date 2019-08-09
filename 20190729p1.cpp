#if 0
#include <stdio.h>

int A[10000 + 10];

int main() {
	int N, M;
	int result = 0;

	scanf("%d%d", &N, &M);

	for (int i = 0; i < N; i++)
		scanf("%d", &A[i]);

	int index = 0;
	int temp = 0;
	int start = 0;

	while (index < N) {
		temp += A[index++];

		if (temp >= M) {
			if (temp == M) {
				result++;
				temp -= A[start++];
				continue;
			}

			while (temp > M) {
				temp -= A[start++];
				if (temp == M) {
					result++;
				}
			}
		}
	}

	printf("%d", result);

	return 0;
}
#endif
//수들의 합 2

#if 0
#include <stdio.h>
int A[100000 + 10];

int main() {
	int N;
	int result = 1000000000;
	int S;
	scanf("%d%d", &N, &S);

	for (int i = 0; i < N; i++)
		scanf("%d", &A[i]);

	int index = 0;
	int temp = A[0];
	int start = 0;

	while (start <= index && index < N) {
		if (temp > S) {
			if (result > index - start + 1)
				result = index - start + 1;
			temp -= A[start++];
		}
		else if (temp == S) {
			if (result > index - start + 1)
				result = index - start + 1;
			temp += A[++index];
		}
		else {
			temp += A[++index];
		}
	}

	if (result == 1000000000)
		printf("0");
	else
		printf("%d", result);

	return 0;
}


#endif
//부분합

#if 0
#include <stdio.h>
int tree[1000000 + 10];

int main() {
	int N;
	unsigned long long M;
	int min = 0;
	int max = 0;
	scanf("%d%llu", &N, &M);

	for (int i = 0; i < N; i++) {
		scanf("%d", &tree[i]);
		if (max < tree[i])
			max = tree[i];
	}

	unsigned long long sum = 0;
	int height = max / 2;
	int priorMaxHeight = 1000000000;

	while (height >= 0) {
		sum = 0;
		height = (min + max) / 2;

		for (int i = 0; i < N; i++) {
			if (tree[i] > height)
				sum += (tree[i] - height);
		}

		if (sum < M) {
			max = height;
		}
		else if (sum == M) {
			break;
		}
		else {
			if (priorMaxHeight == height)
				break;
			priorMaxHeight = height;
			min = height;
		}
	}

	printf("%d\n", height);
	return 0;
}

#endif
// 나무 자르기

#if 0
#include <stdio.h>

long long numbers[90 + 5];

int main() {
	int N;

	numbers[0] = 0;
	numbers[1] = 1;
	numbers[2] = 1;

	for (int i = 3; i <= 90; i++)
		numbers[i] = numbers[i - 1] + numbers[i - 2];

	scanf("%d", &N);

	printf("%lld\n", numbers[N]);

	return 0;
}

#endif
//피보나치 2

#if 0
#include <stdio.h>

int sumMin[100000][3];
int sumMax[100000][3];

int main() {
	int N;
	int a, b, c;

	scanf("%d", &N);

	scanf("%d%d%d", &sumMin[0][0], &sumMin[0][1], &sumMin[0][2]);

	for (int i = 0; i < 3; i++)
		sumMax[0][i] = sumMin[0][i];

	for (int i = 1; i < N; i++) {
		scanf("%d%d%d", &a, &b, &c);
		int temp = 0;
		sumMin[i][0] = sumMin[i - 1][0] + a < sumMin[i - 1][1] + a ? sumMin[i - 1][0] + a : sumMin[i - 1][1] + a;
		sumMin[i][2] = sumMin[i - 1][1] + c < sumMin[i - 1][2] + c ? sumMin[i - 1][1] + c : sumMin[i - 1][2] + c;
		temp = sumMin[i - 1][1] + b < sumMin[i - 1][2] + b ? sumMin[i - 1][1] + b : sumMin[i - 1][2] + b;
		sumMin[i][1] = temp < sumMin[i - 1][0] + b ? temp : sumMin[i - 1][0] + b;

		sumMax[i][0] = sumMax[i - 1][0] + a > sumMax[i - 1][1] + a ? sumMax[i - 1][0] + a : sumMax[i - 1][1] + a;
		sumMax[i][2] = sumMax[i - 1][1] + c > sumMax[i - 1][2] + c ? sumMax[i - 1][1] + c : sumMax[i - 1][2] + c;
		temp = sumMax[i - 1][1] + b > sumMax[i - 1][2] + b ? sumMax[i - 1][1] + b : sumMax[i - 1][2] + b;
		sumMax[i][1] = temp > sumMax[i - 1][0] + b ? temp : sumMax[i - 1][0] + b;
	}

	int min, max, temp;
	temp = sumMax[N - 1][1] > sumMax[N - 1][2] ? sumMax[N - 1][1] : sumMax[N - 1][2];
	max = temp > sumMax[N - 1][0] ? temp : sumMax[N - 1][0];

	temp = sumMin[N - 1][1] < sumMin[N - 1][2] ? sumMin[N - 1][1] : sumMin[N - 1][2];
	min = temp < sumMin[N - 1][0] ? temp : sumMin[N - 1][0];

	printf("%d %d", max, min);
	return 0;
}
#endif // 내려가기

#if 0
#include <stdio.h>

long long game(long long X, long long Y) {
	return Y * 100 / X;
}

int main() {
	long long  X, Y, Z;

	scanf("%lld%lld", &X, &Y);

	Z = Y * 100 / X;

	if (Z >= 99) {
		printf("-1");
		return 0;
	}

	long long plus = (X*(Z + 1) - 100 * Y) / (99 - Z);
	if ((X*(Z + 1) - 100 * Y) % (99 - Z))
		plus++;

	printf("%lld", plus);

	return 0;
}
#endif
// 게임

#if 0
#include<stdio.h>

int numbers[4000][4];
int sumLeft[4000 * 4000];
int sumRight[4000 * 4000];

void sortRight(int s, int e) {
	if (s >= e)
		return;

	int T, L, P;
	T = L = s;
	P = e;

	while (T < P) {
		if (sumRight[T] < sumRight[P]) {
			int temp = sumRight[T];
			sumRight[T] = sumRight[L];
			sumRight[L] = temp;
			L++;
		}
		T++;
	}

	int temp = sumRight[P];
	sumRight[P] = sumRight[L];
	sumRight[L] = temp;

	sortRight(s, L - 1);
	sortRight(L + 1, e);
}

int main() {
	int N;
	int result = 0;
	int a, b;

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d%d%d%d", &numbers[i][0], &numbers[i][1], &numbers[i][2], &numbers[i][3]);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			sumLeft[N*i + j] = -1 * (numbers[i][0] + numbers[j][1]);
			sumRight[N*i + j] = numbers[i][2] + numbers[j][3];
		}
	}

	sortRight(0, N*N - 1);

	int right = N*N;
	int left = 0;

	for (int i = 0; i < right; i++) {

		while (left < right) {
			int mid = (left + right) / 2;

			if (sumLeft[i] > sumRight[mid])
				left = mid + 1;
			else
				right = mid;
		}

		int low = right;

		left = 0;
		right = N*N;


		while (left < right) {
			int mid = (left + right) / 2;

			if (sumLeft[i] >= sumRight[mid])
				left = mid + 1;
			else
				right = mid;
		}

		int high = right;

		result += (high - low);

		left = 0;
		right = N*N;
	}

	printf("%d", result);

	return 0;
}

#endif
// 합이 0인 네 정수(ㅁ)

#if 0
#include <stdio.h>
#include <malloc.h>

typedef struct location {
	int row;
	int col;
}loc;
char map[50 + 2][50 + 2];
int height[50 + 2][50 + 2];

int dx[8] = { 0,1,1,1,0,-1,-1,-1 };
int dy[8] = { -1,-1,0,1,1,1,0,-1 };

int pRow;
int pCol;
int kCounter = 0;

int floodMin(int min, int N) {
	int cHeight[50 + 2][50 + 2] = { 0, };
	int chk[50 + 2][50 + 2] = { 0, };
	loc queue[10000];

	int wp = 0;
	int rp = 0;
	int k = kCounter;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cHeight[i][j] = height[i][j] - min;
	}

	chk[pCol][pRow] = 1;
	queue[wp].col = pCol;
	queue[wp].row = pRow;
	wp++;

	while (wp >= rp) {
		int currentRow = queue[rp].row;
		int currentCol = queue[rp].col;
		rp++;

		for (int i = 0; i < 8; i++) {
			int nx = currentCol + dx[i];
			int ny = currentRow + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= N || chk[ny][nx] == 1 || cHeight[ny][nx] < 0)
				continue;

			chk[ny][nx] = 1;
			queue[wp].col = nx;
			queue[wp].row = ny;
			if (map[ny][nx] == 'K')
				k--;
			wp++;
		}
	}

	if (k != 0)
		return 0;
	else
		return 1;
}

int floodMax(int max, int N) {
	int cHeight[50 + 2][50 + 2] = { 0, };
	int chk[50 + 2][50 + 2] = { 0, };
	loc queue[10000];

	int wp = 0;
	int rp = 0;
	int k = kCounter;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cHeight[i][j] = height[i][j] - max;
	}

	chk[pCol][pRow] = 1;
	queue[wp].col = pCol;
	queue[wp].row = pRow;
	wp++;

	while (wp >= rp) {
		int currentRow = queue[rp].row;
		int currentCol = queue[rp].col;
		rp++;

		for (int i = 0; i < 8; i++) {
			int nx = currentCol + dx[i];
			int ny = currentRow + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= N || chk[ny][nx] == 1 || cHeight[ny][nx] > 0)
				continue;

			chk[ny][nx] = 1;
			queue[wp].col = nx;
			queue[wp].row = ny;
			if (map[ny][nx] == 'K')
				k--;
			wp++;
		}
	}

	if (k != 0)
		return 0;
	else
		return 1;
}

int main() {
	int N;
	int counter = 0;
	int min = 1000000;
	int max = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%c", &map[i][j]);
			if (map[i][j] == 'K')
				counter++;
			else if (map[i][j] == 'P') {
				pRow = i;
				pCol = j;
			}
		}
	}

	kCounter = counter;
	loc *ks = malloc(sizeof(loc)*counter);

	counter = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 'K') {
				ks[counter].row = i;
				ks[counter].col = j;
				counter++;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &height[i][j]);
			if (map[i][j] == 'K' || map[i][j] == 'P') {
				if (height[i][j] > max)
					max = height[i][j];
				if (height[i][j] < min)
					min = height[i][j];
			}

		}
	}

	floodMin(min, N);

	return 0;
}

#endif
// 집배원(a)

#if 0
#include <stdio.h>
int map[10][10];
int enter[2][3];
int people[10][2];
int timeA[10];
int timeB[10];

int getDistance(int x, int y) {
	return (x < y ? y - x : x - y);
}

int main() {
	int T;
	scanf("%d", &T);

	for (int testCase = 1; testCase <= T; testCase++) {
		int N;
		scanf("%d", &N);

		int enterCounter = 0;
		int pCounter = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &map[i][j]);
				if (map[i][j] > 1) {
					enter[enterCounter][0] = i;
					enter[enterCounter][1] = j;
					enter[enterCounter][2] = map[i][j];
					enterCounter++;
				}
				else if (map[i][j] == 1) {
					people[pCounter][0] = i;
					people[pCounter][1] = j;
					pCounter++;
				}
			}
		}

		for (int i = 0; i < pCounter; i++) {
			timeA[i] = getDistance(enter[0][0], people[i][0]) + getDistance(enter[0][1], people[i][1]);
			timeB[i] = getDistance(enter[1][0], people[i][0]) + getDistance(enter[1][1], people[i][1]);
		}



	}

	return 0;
}

#endif
// 점심식사(용민)

#if 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char orders[5][7] = { "push", "pop", "size", "empty", "top" };
char currentOrder[10000][7];
int stack[10000 + 10];
int index = 0;
int getOrder(char *order) {
	for (int i = 0; i < 5; i++) {
		if (strcmp(order, orders[i]) == 0)
			return i;
	}
}

void push(int *x) {
	stack[index++] = *x;
}

int empty() {
	if (index == 0)
		return 1;
	return 0;
}

int size() {
	return index;
}

int top() {
	if (index == 0)
		return -1;

	return stack[index - 1];
}

int pop() {
	if (index == 0)
		return -1;

	return stack[--index];
}

int main() {
	int N;
	scanf("%d", &N);
	int counter = 0;
	while (N--) {
		scanf("%s", currentOrder[counter]);

		int num = getOrder(currentOrder[counter]);
		counter++;
		int x = 0;

		/*push X : 정수 X를 스택에 넣는 연산이다.
			pop : 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다.만약 스택에 들어있는 정수가 없는 경우에는 - 1을 출력한다.
			size : 스택에 들어있는 정수의 개수를 출력한다.
			empty : 스택이 비어있으면 1, 아니면 0을 출력한다.
			top : 스택의 가장 위에 있는 정수를 출력한다.만약 스택에 들어있는 정수가 없는 경우에는 - 1을 출력한다.*/
		switch (num) {
		case 0:
			scanf("%d", &x);
			push(&x);
			break;
		case 1:
			printf("%d\n", pop());
			break;
		case 2:
			printf("%d\n", size());
			break;
		case 3:
			printf("%d\n", empty());
			break;
		case 4:
			printf("%d\n", top());
			break;
		}
	}

	return 0;
}

#endif
// stack 구현

#if 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMBER_OF_ORDERS 6
char orders[NUMBER_OF_ORDERS][7] = { "push", "pop", "size", "empty", "front", "back" };
char currentOrder[10000][7];
int queue[10000 + 5];
int rear = 0;
int first = 0;

int getOrder(char *order) {
	for (int i = 0; i < NUMBER_OF_ORDERS; i++) {
		if (strcmp(order, orders[i]) == 0)
			return i;
	}
}
int empty() {
	if (rear == first)
		return 1;
	return 0;
}

void push(int *x) {
	queue[rear++] = *x;
}

int pop() {
	if (empty() == 1)
		return -1;

	return queue[first++];
}

int size() {
	return rear - first;
}

int front() {
	if (empty() == 1)
		return -1;

	return queue[first];
}

int back() {
	if (empty() == 1)
		return -1;

	return queue[rear - 1];
}

int main() {
	int N;
	scanf("%d", &N);
	int counter = 0;
	while (N--) {
		scanf("%s", currentOrder[counter]);

		int num = getOrder(currentOrder[counter]);
		counter++;
		int x = 0;

		/*push X : 정수 X를 큐에 넣는 연산이다.
	pop : 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다.만약 큐에 들어있는 정수가 없는 경우에는 - 1을 출력한다.
	size : 큐에 들어있는 정수의 개수를 출력한다.
	empty : 큐가 비어있으면 1, 아니면 0을 출력한다.
	front : 큐의 가장 앞에 있는 정수를 출력한다.만약 큐에 들어있는 정수가 없는 경우에는 - 1을 출력한다.
	back : 큐의 가장 뒤에 있는 정수를 출력한다.만약 큐에 들어있는 정수가 없는 경우에는 - 1을 출력한다.*/
		switch (num) {
		case 0:
			scanf("%d", &x);
			push(&x);
			break;
		case 1:
			printf("%d\n", pop());
			break;
		case 2:
			printf("%d\n", size());
			break;
		case 3:
			printf("%d\n", empty());
			break;
		case 4:
			printf("%d\n", front());
			break;
		case 5:
			printf("%d\n", back());
			break;
		}
	}

	return 0;
}
#endif
// queue 구현

#if 0
#include <stdio.h>
char order[32];
char stack[32];

int index = 0;
int stackIndex = 0;
int length;
int totalSum = 0;

int getK() {
	int i = 0;
	int K = 1;
	while (i < length) {

		switch (order[i]) {
		case '(': K *= 2; break;
		case '{': K *= 3; break;
		case ')': K /= 2; break;
		case '}': K /= 3; break;
		}
		i++;
	}

	if (K != 1)
		return -1;
	else
		return 1;
}

int DFS(int end) {
	int sum = 0;

	while (index < length) {
		char temp = order[index++];

		switch (temp) {
		case '(': stackIndex++; sum += 2 * DFS(end + 1); break;
		case '[': stackIndex++; sum += 3 * DFS(end + 1); break;
		case ')': stackIndex--;
			if (stackIndex == end)
				sum = 1;
			break;
		case ']': stackIndex--;
			if (stackIndex == end)
				sum = 1;
			break;
		}

		if (stackIndex == end) {
			return sum;
		}
	}
}

int topCompare() {
	while (index < length) {
		char temp = order[index];

		switch (temp) {
		case '(': stackIndex++; totalSum += 2 * DFS(stackIndex - 1); break;
		case '[': stackIndex++; totalSum += 3 * DFS(stackIndex - 1); break;
		}
	}

	return totalSum;
}



int main() {
	scanf("%s", order);

	length = 0;
	while (order[length++]);
	length--;

	if (length % 2 || getK() != 1) {
		printf("-1");
		return 0;
	}

	index = 0;
	printf("%d", topCompare());

	return 0;
}


#endif
//괄호의 값(ㅁ)

#if 0
#include <stdio.h>
#define SIZE 5000000

int A[SIZE + 1];
int D[SIZE + 1];
int queue[SIZE + 1];
int index = 1;
int priority = 1;

//int insert(int key) {
//	if (index == 1) {
//		data *temp = malloc(sizeof(data));
//		temp->priority = priority;
//		temp->key = key;
//		queue[index++] = temp;
//		return;
//	}
//	
//	data *temp = malloc(sizeof(data));
//	temp->priority = priority;
//	temp->key = key;
//	queue[index] = temp;
//
//	int tempIndex = index;
//	while (tempIndex != 1 && queue[tempIndex / 2] > queue[tempIndex]) {
//		int temp = queue[tempIndex /2];
//		queue[tempIndex / 2] = queue[tempIndex];
//		queue[tempIndex] = temp;
//		tempIndex /= 2;
//	}
//
//	index++;
//	return queue[1];
//}

void clear() {

}

int main() {
	int L, N;

	scanf("%d%d", &N, &L);

	A[0] = 1000000000 + 1;

	for (int i = 1; i <= N; i++)
		scanf("%d", &A[i]);

	int counter = L + 1;
	int min = A[1];

	for (int i = 1; i <= L; i++)
		D[i] = min;

	while (counter != N) {
		D[counter] = insert(A[counter]);
		counter++;
	}

	return 0;
}
#endif
//최솟값 찾기(ㅁ)

#if 0
#include <stdio.h>
#include <malloc.h>
typedef struct node_ {
	char data;
	struct node_ *left;
	struct node_ *right;
}node;

node *root = NULL;
node *address[26];

node *make(char data, char dataLeft, char dataRight) {
	node *temp;
	if (address[data - 'A'])
		temp = address[data - 'A'];
	else
		temp = malloc(sizeof(node));

	temp->data = data;

	if (dataLeft == '.')
		temp->left = NULL;
	else {
		node *temp2 = malloc(sizeof(node));
		temp2->data = dataLeft;
		temp->left = temp2;
		address[dataLeft - 'A'] = temp2;
	}

	if (dataRight == '.')
		temp->right = NULL;
	else {
		node *temp2 = malloc(sizeof(node));
		temp2->data = dataRight;
		temp->right = temp2;
		address[dataRight - 'A'] = temp2;
	}

	address[data - 'A'] = temp;
	return temp;
}

void preOrder(node *temp) {
	printf("%c", temp->data);
	if (temp->left)
		preOrder(temp->left);
	if (temp->right)
		preOrder(temp->right);
}

void postOrder(node *temp) {
	if (temp->left)
		postOrder(temp->left);
	if (temp->right)
		postOrder(temp->right);
	printf("%c", temp->data);
}

void inOrder(node *temp) {
	if (temp->left)
		inOrder(temp->left);
	printf("%c", temp->data);
	if (temp->right)
		inOrder(temp->right);
}

int main() {
	int N;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		char input[10];
		char data;
		char child1, child2;

		gets(input);
		if (input[0] == '\0') {
			i--;
			continue;
		}
		data = input[0];
		child1 = input[2];
		child2 = input[4];


		make(data, child1, child2);
	}

	preOrder(address[0]);
	printf("\n");
	inOrder(address[0]);
	printf("\n");
	postOrder(address[0]);
	printf("\n");

	return 0;
}

#endif
//트리 순회

#if 0
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10000

int input[MAX_SIZE];

void getTree(int index, int rr) {
	if (index >= 10000)
		return;
	if (input[index] == 0)
		return;

	int left = 10000;
	int right = 10000;

	if (input[index + 1] != 0 && input[index + 1] < input[index])
		left = index + 1;
	for (int i = index + 1; i < rr; i++) {
		if (input[i] > input[index]) {
			right = i;
			break;
		}
	}

	getTree(left, right);
	getTree(right, rr);
	printf("%d\n", input[index]);
}

int main() {
	//char temp[8];
	int a;
	int i = 0;
	int length = 0;

	while (scanf(" %d", &a) != -1)
		input[i++] = a;

	int left = 10000;
	int right = 10000;
	if (input[1] != 0 && input[1] < input[0])
		left = 1;
	for (int i = 1; i < MAX_SIZE; i++) {
		if (input[i] > input[0]) {
			right = i;
			break;
		}
	}

	getTree(left, right);
	getTree(right, MAX_SIZE);
	printf("%d\n", input[0]);

	return 0;
}

#endif
// 이진검색트리(입력?)

#if 0
#include <stdio.h>
#define MAX_SIZE 10000

int numbers[100];

typedef struct node_ {
	int key;
	int p;
}node;

int queue[MAX_SIZE];
int index = 1;
void insert(int data) {
	if (queue[1] == 0) {
		queue[1] = data;
		return;
	}

	queue[index] = data;

	int tempIndex = index;
	while (queue[tempIndex / 2] > queue[tempIndex]) {
		int temp = queue[tempIndex];
		queue[tempIndex] = queue[tempIndex / 2];
		queue[tempIndex / 2] = temp;
	}

}

int main() {
	int K, N;

	for (int i = 0; i < K; i++) {
		scanf("%d", &numbers[i]);
		insert(numbers[i]);
		index++;
	}

	queue


		return 0;
}

#endif

#if 0
#include <stdio.h>
#define MAX_INT 0x7FFFFFFF
#define MAX_MAP 100

int map[100][100];


int main() {
	int N, M;
	for (int i = 0; i < MAX_MAP; i++) {
		for (int j = 0; j < MAX_MAP; j++)
			map[i][j] = MAX_INT;
	}

	scanf("%d%d", &N, &M);

	for (int i = 0; i < M; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		if (c < map[a - 1][b - 1])
			map[a - 1][b - 1] = c;
	}

	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (i == j)
					continue;

				if (map[i][k] == MAX_INT || map[k][j] == MAX_INT)
					continue;

				if (map[i][j] > map[i][k] + map[k][j])
					map[i][j] = map[i][k] + map[k][j];
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == MAX_INT)
				map[i][j] = 0;
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}

	return 0;
}

#endif
//플로이드

#if 0
#include <stdio.h>

int student[500][500];
int chk[500];
int N;

void clear() {
	for (int j = 0; j < N; j++)
		chk[j] = 0;
}

void forward(int index, int dir) {
	for (int i = 0; i < N; i++) {
		if (student[index][i] == dir && chk[i] != 1) {
			chk[i] = 1;
			forward(i, dir);
		}
	}
}

int main() {
	int M;

	scanf("%d%d", &N, &M);

	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d%d", &a, &b);

		student[a - 1][b - 1] = 1;
		student[b - 1][a - 1] = -1;
	}

	int result = 0;

	for (int i = 0; i < N; i++) {
		int forwardSum = 0, backwardSum = 0;

		clear();
		chk[i] = 1;

		for (int j = 0; j < N; j++) {
			if (student[i][j] == 1) {
				chk[j] = 1;
				forward(j, 1);
			}
		}

		for (int j = 0; j < N; j++)
			if (chk[j] == 1) forwardSum++;

		clear();
		chk[i] = 1;

		for (int j = 0; j < N; j++) {
			if (student[i][j] == -1) {
				chk[j] = 1;
				forward(j, -1);
			}
		}

		for (int j = 0; j < N; j++)
			if (chk[j] == 1) backwardSum++;

		if (forwardSum + backwardSum == N + 1)
			result++;
	}

	printf("%d", result);

	return 0;
}

#endif
//키순서

#if 0
#include <stdio.h>
#define MAX_SIZE 1000001
#define MAX_INPUT 100000

int number[MAX_SIZE];

int find(int n) {
	if (n == number[n])	return n;
	if (n == 0 && number[n] == 1000000000) return 0;

	return number[n] = find(number[n]);
}

void unionSet(int a, int b) {
	if (a == b)	return;
	number[find(a)] = find(b);
}

int checkSet(int a, int b) {
	return find(a) == find(b);
}

int main() {
	int N, M;

	scanf("%d%d", &N, &M);

	number[0] = 1000000000;
	for (int i = 1; i <= N; i++)
		number[i] = i;

	for (int i = 0; i < M; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);

		switch (a) {
		case 0:
			unionSet(b, c);
			break;
		case 1:
			if (checkSet(b, c))
				printf("YES\n");
			else
				printf("NO\n");
			break;
		}
	}

	return 0;
}

#endif
//Union-find

#if 0
#include <stdio.h>
#define MAX_SIZE 1000
#define MAX_INT 0x7fffffff

int map[MAX_SIZE][MAX_SIZE];
int connected[MAX_SIZE];
int chk[MAX_SIZE];

int main() {
	int N, M;

	scanf("%d%d", &N, &M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			map[i][j] = MAX_INT;
	}

	for (int i = 0; i < M; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		if (c < map[a - 1][b - 1]) {
			map[a - 1][b - 1] = c;
			map[b - 1][a - 1] = c;
		}
	}

	int connectedCounter = 1;
	int totalCost = 0;
	chk[0] = 1;
	connected[0] = 0;

	while (connectedCounter < N) {
		int minCost = 0x7fffffff;
		int minLocation = -1;

		for (int i = 0; i < connectedCounter; i++) {
			for (int j = 0; j < N; j++) {
				if (chk[j] == 0) {
					if (minCost > map[connected[i]][j]) {
						minCost = map[connected[i]][j];
						minLocation = j;
					}
				}
			}
		}

		connected[connectedCounter++] = minLocation;
		chk[minLocation] = 1;
		totalCost += minCost;
	}

	printf("%d", totalCost);
	return 0;
}
#endif
//네트워크 연결

#if 0
#include <stdio.h>
#define MAX_STUDENT 32000
#define MAX_COMPARE 100000

int list[MAX_STUDENT][2];
int queue[MAX_COMPARE + 10];
int chk[MAX_STUDENT + 1];

int wp, rp, N, M;

void push(int index) {
	queue[wp++] = index;
}

void poll() {
	while (rp < wp) {
		printf("%d ", queue[rp]);

		int temp = queue[rp];
		chk[temp] = -1;
		rp++;

		for (int i = 0; i < M; i++) {
			if (list[i][0] == temp)
				chk[list[i][1]]--;
		}
	}

	for (int i = 1; i <= N; i++) {
		if (chk[i] == 0)
			push(i);
	}
}

int main() {
	scanf("%d%d", &N, &M);

	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d%d", &a, &b);

		list[i][0] = a;
		list[i][1] = b;
		chk[b]++;
	}

	if (N == 1) {
		printf("1");
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (chk[i] == 0)
			push(i);
	}

	if (wp != rp) {
		poll();
	}

	return 0;
}

#endif
// 줄세우기 ㅁ

#if 0
#include <stdio.h>
#include<vector>

#define MAX 32001

int N, M, a, b;
int degree[MAX];// c로 하면 어떻게 해야할까?

int main() {


	return 0;
}

#endif
// 줄세우기

#if 0
#include <stdio.h>
int buildTime[500];
int list[500][500];
int chk[500];
int built[500];
int N;

int dfs(int currentBuild) {
	if (built[currentBuild] != 0)
		return built[currentBuild];

	int sum = buildTime[currentBuild];

	int min = 1000000;
	for (int i = 0; i < N; i++) {
		int temp = dfs(i);
		if (temp < min)
			min = temp;
	}

	return built[currentBuild] = sum + min;
}

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &buildTime[i]);

		int a = 0;
		int flag = 0;
		scanf("%d", &a);
		while (a != -1) {
			flag = 1;
			list[i][a - 1] = 1;
			scanf("%d", &a);
		}

		if (flag == 0)
			built[i] = buildTime[i];
	}

	for (int i = 0; i < N; i++) {
		if (built[i] != 0) {
			printf("%d\n", built[i]);
			continue;
		}

		int sum = buildTime[i];
		int min = 1000000;
		for (int j = 0; j < N; j++) {
			if (i == j)
				continue;

			if (list[i][j] == 1) {
				int temp = dfs(j);
				if (min > temp)
					min = temp;
			}

		}
		printf("%d\n", sum + min);
		built[i] = sum + min;
	}

	return 0;
}
#endif
//게임개발(mine)

#if 0
#include <stdio.h>
#define MAX_SIZE 501

int buildTime[MAX_SIZE];
int minTime[MAX_SIZE];
int degree[MAX_SIZE];
int list[MAX_SIZE][MAX_SIZE];
int queue[MAX_SIZE * 2];

int N, a, b;
int rp, wp;

int main() {

	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		list[i][0] = 1;
	}

	for (int i = 1; i <= N; i++) {
		scanf("%d%d", &a, &b);
		buildTime[i] = a;
		minTime[i] = a;

		while (b != -1) {
			list[b][list[b][0]++] = i;
			degree[i]++;
			scanf("%d", &b);
		}
	}

	for (int i = 1; i <= N; i++) {
		if (degree[i] == 0)
			queue[wp++] = i;
	}

	while (rp < wp) {
		int sum = queue[rp++];

		for (int i = 1; i < list[sum][0]; i++) {
			int index = list[sum][i];
			degree[index]--;
			if (degree[index] == 0)
				queue[wp++] = list[sum][i];
			minTime[index] = minTime[index] > minTime[sum] + buildTime[index] ? minTime[index] : minTime[sum] + buildTime[index];
		}

	}

	for (int i = 1; i <= N; i++) {
		printf("%d\n", minTime[i]);
	}

	return 0;
}

#endif
// 게임개발 소스

#if 0
#include <stdio.h>
#define INT_MAX 0x7fffffff
#define MAX_SIZE 20000

typedef struct node_ {
	int dist;
	int prior;
}node;

node *queue[MAX_SIZE + 1];
int lastIndex = 1;

void insert(node *n) {
	queue[lastIndex] = n;

	int index = lastIndex;
	while (queue[index / 2]->dist > queue[index]->dist) {
		node *temp = queue[index / 2];
		queue[index / 2] = queue[index];
		queue[index] = temp;
		index /= 2;
	}

	lastIndex++;
}

node *getNode() {
	node *output = queue[1];

	queue[1] = queue[lastIndex - 1];
	queue[--lastIndex] = NULL;

	int index = 1;
	while (queue[index]->dist > queue[index * 2]->dist) {
		node *temp = queue[index / 2];
		queue[index / 2] = queue[index];
		queue[index] = temp;
		index /= 2;
	}
}

int main() {
	int V, E, start;

	scanf("%d%d%d", &V, &E, &start);


	for (int i = 0; i < E; i++) {

	}

	return 0;
}

#endif
//최단경로 ㅁ

#if 0
#include <stdio.h>
#include <queue>

using namespace std;

typedef struct node_ {
	int start;
	int end;
}node;

int V, E, K;

queue<int> q;
vector<node> vt;

int main() {
	scanf("%d%d%d", &V, &E, &K);

	for (int i = 0; i < E; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		node *temp = new node;
		temp->start
	}

	return 0;
}

#endif

#if 0
#include <stdio.h>
#define MAX_SIZE 501
#define MAX_INT 100000

int path[MAX_SIZE][3];
int dist[MAX_SIZE];
int N, M;

void relax(int start, int end, int cost) {
	if (dist[start] == MAX_INT)
		return;

	if (dist[end] > dist[start] + cost)
		dist[end] = dist[start] + cost;
}

int check(int start, int end, int cost) {
	int chk = 0;

	if (dist[start] == MAX_INT || dist[end] == MAX_INT)
		return 0;

	if (dist[end] > dist[start] + cost) {
		dist[end] = dist[start] + cost;
		chk = 1;
	}

	return chk;
}

int main() {
	scanf("%d%d", &N, &M);

	for (int i = 0; i <= N; i++)
		dist[i] = MAX_INT;

	dist[1] = 0;

	for (int i = 0; i < M; i++) {
		int a, b, c;
		scanf("%d%d%d", &path[i][0], &path[i][1], &path[i][2]);
	}

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < M; j++)
			relax(path[j][0], path[j][1], path[j][2]);
	}

	int flag = 1;

	for (int j = 0; j < M; j++) {
		if (path[j][0] == MAX_INT)
			continue;
		if (check(path[j][0], path[j][1], path[j][2])) {
			flag = 0;
			break;
		}
	}

	if (flag) {
		for (int i = 2; i <= N; i++) {
			if (dist[i] == MAX_INT) {
				printf("-1\n");
				continue;
			}

			printf("%d\n", dist[i]);
		}
	}
	else
		printf("-1");

	return 0;
}
#endif
// 타임머신 : 벨만포드

#if 0
#include <stdio.h>
#include <vector>
#include <queue>

#define MAX_SIZE 100000
#define MAX_DEPTH 17

using namespace std;

vector<int> adj[MAX_SIZE + 1];
int depth[MAX_SIZE + 1];
int parent[MAX_DEPTH + 1][MAX_SIZE + 1];

int N, M;


int main() {
	scanf("%d", &N);

	for (int i = 0; i <= N; i++) //초기화
		depth[i] = -1;

	for (int i = 1; i < N; i++) {
		int a, b;
		scanf("%d%d", &a, &b);

		adj[a].push_back(b);
		adj[b].push_back(a); //양방향 그래프
	}

	queue<int> q;
	depth[1] = 0;
	parent[0][1] = 0;
	q.push(1); // 1은 루트노드 이므로 push

	while (!q.empty()) {
		int current = q.front();
		q.pop();

		for (int i = 0; i < adj[current].size(); i++) {
			int node = adj[current][i];

			if (depth[node] == -1) {
				depth[node] = depth[current] + 1;
				parent[0][node] = current;
				q.push(node);
			}
		}
	}

	for (int i = 1; i <= MAX_DEPTH; i++) {
		for (int j = 1; j <= N; j++)
			parent[i][j] = parent[i - 1][parent[i - 1][j]];
	}

	scanf("%d", &M);

	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d%d", &a, &b);

		if (depth[a] > depth[b]) {
			int temp = a;
			a = b;
			b = temp;
		}

		for (int j = MAX_DEPTH; j >= 0; j--) {
			if (depth[a] <= depth[parent[j][b]]) {
				b = parent[j][b];
			}
		}

		for (int k = MAX_DEPTH; k >= 0 && a != b; k--) {
			if (parent[k][a] != parent[k][b]) {
				a = parent[k][a];
				b = parent[k][b];
			}
		}

		int result = a;

		if (a != b)
			result = parent[0][result];

		printf("%d\n", result);
	}

	return 0;
}

#endif
// LCA2
#if 0
#include <stdio.h>

int main() {
	int N;

	while (scanf("%d", &N) != -1) {
		int digit = 1;
		int cal = 1 % N;

		while (cal != 0) {
			digit++;
			cal = (cal * 10 + 1) % N;
		}

		printf("%d\n", digit);
	}

	return 0;
}

#endif
//1

#if 0
#include <stdio.h>

int main() {
	int N;

	scanf("%d", &N);

	int div = 2;
	while (N != 1) {
		while (N % div == 0) {
			N /= div;
			printf("%d\n", div);
			if (N == 1)
				break;
		}
		div++;
	}
	return 0;
}

#endif
//소인수분해(시간초과)

#if 0
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

char number[100000 + 10];

vector<int> vt;

int main() {
	scanf("%s", number);

	int i = 0;
	int sum = 0;
	while (number[i]) {
		vt.push_back(number[i] - '0');
		i++;
	}

	sort(vt.begin(), vt.end());


	for (int j = 1; j < (signed)vt.size(); j++) {
		sum += vt[j];
	}

	if (vt.front() != 0 || sum % 3 != 0) {
		printf("-1\n");
	}
	else {
		for (int k = vt.size() - 1; k >= 0; k--)
			printf("%d", vt[k]);
	}

	return 0;
}

#endif
//30

#if 0
#include <stdio.h>

int chk[1000 + 1];

int main() {
	int N, K;

	scanf("%d%d,", &N, &K);

	for (int i = 2; i <= N; i++) {
		chk[i] = 1;
	}

	int deleted = 0;
	int index = 2;
	int cur = 2;

	while (deleted < K) {
		for (int i = index; i <= N; i += index) {
			if (chk[i] == 1) {
				deleted++;
				chk[i] = 0;
				cur = i;
			}

			if (deleted == K) {
				printf("%d", cur);
				return 0;
			}
		}

		while (chk[index] != 1) index++;
	}

	return 0;
}
#endif
//에라토스테네스의 체

#if 0
#include <stdio.h>
#include <vector>

using namespace std;

vector<int> vt;
int chk[4000000 + 1];
int main() {
	int N;

	scanf("%d", &N);

	int index = 2;

	vt.push_back(0);
	while (index <= N) {
		vt.push_back(index);
		for (int i = index; i <= N; i += index)
			chk[i] = 1;

		while (chk[index] == 1) index++;
	}

	int start = 1;
	int end = 0;
	int sum = vt[1];
	int result = 0;

	int size = vt.size();
	while (start < size) {
		if (sum < N) {
			if (start + 1 < size)
				sum += vt[++start];
			else
				break;
		}
		else if (sum > N)
			sum -= vt[end++];
		else {
			result++;
			if (start + 1 < size)
				sum += vt[++start];
			else
				break;
		}
	}

	printf("%d", result);
	return 0;
}

#endif
//소수의 연속합

#if 0
#include <stdio.h>
#include <vector>
#define MAX_SIZE 1000100

using namespace std;

vector<int> inputs;
vector<int> prime;
int chk[MAX_SIZE / 2 + 1];

int checkPrime(int a) {
	if (a < MAX_SIZE / 2 && chk[a] == 0)
		return 1;

	for (int i = 0; i < prime.size(); i++) {
		if (a%prime[i] == 0)
			return 0;
	}

	return 1;
}

int main() {
	int N;

	int index = 2;
	chk[0] = chk[1] = 1;

	while (index < MAX_SIZE / 2) {
		prime.push_back(index);
		for (int i = index * 2; i <= MAX_SIZE / 2; i += index) {
			chk[i] = 1;
		}

		index++;
		while (index < MAX_SIZE && chk[index] == 1) index++;
	}

	scanf("%d", &N);

	while (N) {
		inputs.push_back(N);
		scanf("%d", &N);
	}

	int inputIndex = 0;
	while (inputIndex < inputs.size()) {
		int target = inputs[inputIndex++];
		int flag = 0;
		int lowerIndex = 0;

		while (prime[lowerIndex] < target) {
			if (checkPrime(target - prime[lowerIndex])) {
				flag = 1;
				printf("%d = %d + %d\n", target, prime[lowerIndex], target - prime[lowerIndex]);
				break;
			}

			lowerIndex++;
		}

		if (flag == 0)
			printf("Goldbach's conjecture is wrong.\n");
	}

	return 0;
}

#endif
// 골드바흐의 추측

#if 0
#include <stdio.h>
int a, b, c, d;

int main() {
	scanf("%d%d%d%d", &a, &b, &c, &d);

	int up = a*d + b*c;
	int down = b*d;
	int reversed = up > down;
	int r = 0;
	int temp;

	while (1) {
		if (up < down) {
			temp = down;
			down = up;
			up = temp;
		}

		if (up%down == 0) {
			r = down;
			break;
		}

		up = up%down;
	}

	printf("%d %d", (a*d + b*c) / r, (b*d) / r);

	return 0;
}

#endif
//분수 합


#if 0
#include <stdio.h>
#include <vector>

using namespace std;

vector<int> vt1;
vector<int> vt2;


int main() {
	int N, M;
	unsigned long long A = 1;
	unsigned long long B = 1;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int temp;
		scanf("%d", &temp);
		vt1.push_back(temp);
	}

	scanf("%d", &M);

	for (int i = 0; i < M; i++) {
		int temp;
		scanf("%d", &temp);
		vt2.push_back(temp);
	}

	unsigned long long r = 0;
	unsigned long long tempA = 1;
	unsigned long long tempB = 1;

	int index = (N > M ? N : M);
	N--;
	M--;
	while (index--) {
		if (N >= 0)
			tempA *= vt1[N];

		if (M >= 0)
			tempB *= vt2[M];


		N--; M--;

		while (1) {
			if (tempA < tempB) {
				unsigned long long temp = tempA;
				tempA = tempB;
				tempB = temp;
			}

			if (!(tempA%tempB)) {
				r = tempB;
				break;
			}

			tempA = tempA%tempB;
		}

		tempA = r;
		tempB = r;
	}

	if (r > 1000000000)
		printf("%09llu", r % 1000000000);
	else
		printf("%llu", r);

	return 0;
}

#endif
//asdf

#if 0
#include <stdio.h>
#include <vector>
#define MAX 100

using namespace std;

vector<int> prime;
int chk[1000 + 1];
int numbers[MAX][1000 + 1];
int sum[1000 + 1];
int totalSum[1000 + 1];
int totalCounter = 0;
int result = 1;
int main() {
	int N;
	int cur = 2;

	while (cur < 1000) {
		for (int i = cur; i <= 1000; i += cur) {
			prime.push_back(cur);
			chk[i] = 1;
		}

		while (chk[cur] == 1) cur++;
	}

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d", &numbers[i][0]);

	int size = prime.size();
	int counter = 0;

	for (int i = 0; i < N; i++) {
		int index = prime[counter];

		while (counter < size) {
			while (numbers[i][0] % index == 0) {
				numbers[i][index]++;
				numbers[i][0] /= index;
			}
			index = prime[counter++];
		}

		counter = 0;
	}

	for (int i = 0; i < N; i++) {
		counter = 0;
		int index = prime[counter];
		while (counter < size) {
			sum[index] += numbers[i][index];
		}
		counter++;
	}

	for (int i = 0; i < N; i++) {
		sum[i] /= N;
	}

	for (int j = 0; j < N; j++) {
		for (int i = 0; i < 1000; i++) {
			if (numbers[j][i] > sum[i]) {
				totalSum[i] += (numbers[j][i] - sum[i]);
				totalCounter++;
			}
		}
	}

	for (int i = 0; i < 1000; i++) {
		while (sum[i] != 0) {
			sum[i]--;
			result *= i;
		}
	}

	printf("%d %d", result, totalCounter);

	return 0;
}

#endif

#if 0
#include <stdio.h>

int numbers[11] = { 1,1,2, 6, 24,120,720,5040,40320,362880,3628800 };

int main() {
	int N, K;

	scanf("%d%d", &N, &K);

	printf("%d", numbers[N] / (numbers[N - K] * numbers[K]));

	return 0;
}
#endif
//이항계수1

#if 0
#include <stdio.h>
#define MOD 10007

int numbers[1000 + 1][1000 + 1];

int main() {
	int N, K;
	int temp = 1;

	scanf("%d%d", &N, &K);

	numbers[0][0] = 1;

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0)
				numbers[i][j] = numbers[i - 1][j] % MOD;
			else
				numbers[i][j] = (numbers[i - 1][j - 1] + numbers[i - 1][j]) % MOD;
		}
	}

	printf("%d", numbers[N][K]);

	return 0;
}

#endif
//이항계수 2(파스칼의 삼각형)

#if 0
#include <stdio.h>
#define MAX 30

unsigned int map[MAX + 1][MAX + 1];
int N, M;

int main() {
	int testCase;

	map[0][0] = 1;

	for (int i = 1; i <= 30; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0)
				map[i][j] = map[i - 1][j];
			else
				map[i][j] = map[i - 1][j] + map[i - 1][j - 1];
		}
	}

	scanf("%d", &testCase);

	for (int t = 1; t <= testCase; t++) {
		scanf("%d%d", &N, &M);

		printf("%u\n", map[M][N]);
	}

	return 0;
}

#endif
//다리놓기(파스칼 삼각형)

#if 0
#include <stdio.h>
#define MAX 100
#define LIMIT 1000000000

unsigned long long numbers[2 * MAX + 1][2 * MAX + 1];
unsigned long long temp;
char result[200 + 2];
int N, M, K;
int size, cur;
int index = 0;

int main() {
	scanf("%d%d%d", &N, &M, &K);
	numbers[0][0] = 1;
	size = N + M;

	for (int i = 1; i <= 200; i++) {
		for (int j = 0; j <= 200; j++) {
			if (j == 0) {
				numbers[i][j] = numbers[i - 1][j];
				if (numbers[i][j] > LIMIT)
					numbers[i][j] = LIMIT;
			}
			else {
				numbers[i][j] = numbers[i - 1][j - 1] + numbers[i - 1][j];
				if (numbers[i][j] > LIMIT)
					numbers[i][j] = LIMIT;
			}
		}
	}

	int flag = 0;

	if (numbers[size][M] >= K) {
		flag = 1;
	}

	if (!flag) {
		printf("-1");
		return 0;
	}

	index = 0;
	cur = 0;
	while (cur != K && N != 0 && M != 0) {
		if (numbers[N + M - 1][M] >= K - cur) {
			result[index] = 'a';
			N--;
		}
		else {
			result[index] = 'z';
			cur += numbers[N + M - 1][M];
			M--;
		}

		index++;
	}

	while (N != 0) {
		result[index++] = 'a';
		N--;
	}

	while (M != 0) {
		result[index++] = 'z';
		M--;
	}

	result[index] = '\0';

	printf("%s", result);
	return 0;
}

#endif
//사전

#if 0
#include <stdio.h>
#include <set>
#include <stdlib.h>

using namespace std;

set<int> st;

int n, k, total;
string dp[10 + 1][10 + 1][10 + 1];
string numbers;

int main() {
	scanf("%d%d", &n, &k);

	for (int i = 1; i <= n; i++) {
		scanf("%s", &numbers);
		dp[i][0][0] = numbers;
	}


	for (int i = 1; i < n; i++) {

	}

	return 0;
}

#endif
// 카드놓기(ㅁ)

#if 0
#include <stdio.h>

int numbers[101];
int result;
unsigned long long dp[100 + 1][20 + 1];

int main() {
	int N;

	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &numbers[i]);
	}

	result = numbers[N];

	dp[1][numbers[1]] = 1;

	for (int i = 2; i < N; i++) {
		for (int j = 0; j <= 20; j++) {
			if (dp[i - 1][j] != 0) {
				if (j + numbers[i] >= 0 && j + numbers[i] <= 20)
					dp[i][j + numbers[i]] += dp[i - 1][j];
				if (j - numbers[i] >= 0 && j - numbers[i] <= 20)
					dp[i][j - numbers[i]] += dp[i - 1][j];
			}
		}
	}

	printf("%llu", dp[N - 1][result]);
	return 0;
}

#endif
//1학년

#if 0
#include <stdio.h>

int map[1000 + 2][1000 + 2];
unsigned long long counter[1000 + 2][1000 + 2];

int H, W, N;

int main() {
	scanf("%d%d%d", &H, &W, &N);

	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	counter[1][1] = N - 1;

	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			if (counter[i][j] == 0)
				continue;

			counter[i + 1][j] += counter[i][j] / 2;
			counter[i][j + 1] += counter[i][j] / 2;

			if (counter[i][j] % 2) {
				if (map[i][j])
					counter[i][j + 1]++;
				else
					counter[i + 1][j]++;
			}

			map[i][j] = (int)(((unsigned long long)map[i][j] + counter[i][j]) % 2);
		}
	}

	int row = 1, col = 1;

	while (row <= H && col <= W) {
		if (map[row][col])
			col++;
		else
			row++;
	}

	printf("%d %d", row, col);

	return 0;
}

#endif
//산책

#if 0
#include <stdio.h>
int stairs[300 + 1];
int dp1[300 + 1];
int dp2[300 + 1];
int N;

int main() {
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
		scanf("%d", &stairs[i]);

	dp1[0] = dp2[0] = dp2[1] = 0;
	dp1[1] = stairs[1];
	if (N >= 2) {
		dp1[2] = dp1[1] + stairs[2];
		dp2[2] = stairs[2];
	}

	for (int i = 3; i <= N; i++) {
		dp1[i] = dp2[i - 1] + stairs[i];

		dp2[i] = dp1[i - 2] > dp2[i - 2] ?
			dp1[i - 2] + stairs[i] : dp2[i - 2] + stairs[i];
	}

	int result = dp1[N] > dp2[N] ? dp1[N] : dp2[N];
	printf("%d", result);

	return 0;
}

#endif
//계단오르기

#if 0
#include <stdio.h>
int map[500 + 1][500 + 1];
unsigned long long dp[500 + 1][500 + 1];

int main() {
	int n;

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	dp[1][1] = map[1][1];

	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= i + 1; j++) {
			dp[i + 1][j] = dp[i + 1][j] > dp[i][j] + map[i + 1][j] ?
				dp[i + 1][j] : dp[i][j] + map[i + 1][j];

			if (j + 1 <= n) {
				dp[i + 1][j + 1] = dp[i + 1][j + 1] > dp[i][j] + map[i + 1][j + 1] ?
					dp[i + 1][j + 1] : dp[i][j] + map[i + 1][j + 1];
			}
		}
	}

	unsigned long long max = 0;
	for (int i = 1; i <= n; i++) {
		if (max < dp[n][i])
			max = dp[n][i];
	}

	printf("%llu", max);

	return 0;
}

#endif
//삼각형

#if 0
#include <stdio.h>

int map[1000 + 1][1000 + 1];
int n, m, sum;

int min(int a, int b) {
	return a < b ? a : b;
}

int main() {
	scanf("%d%d", &n, &m);

	for (int i = 1; i <= n; i++) {
		char input[1002];
		scanf("%s", &input);

		for (int j = 1; j <= m; j++) {
			map[i][j] = input[j - 1] - '0';

			if (map[i][j] > 0)
				sum = 1;
		}
	}


	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= m; j++) {
			if (sum < map[i][j])
				sum = map[i][j];

			if (map[i - 1][j - 1] > 0 && map[i - 1][j] > 0 &&
				map[i][j - 1] > 0 && map[i][j] > 0) {
				map[i][j] = min(min(map[i - 1][j - 1], map[i - 1][j]), map[i][j - 1]) + 1;

				if (map[i][j] > sum)
					sum = map[i][j];
			}
		}
	}

	printf("%d", sum*sum);

	return 0;
}
#endif
//가장 큰 정사각형

#if 0
#include <stdio.h>
int sum[100000 + 1];
int N, M;

int main() {
	scanf("%d%d", &N, &M);

	for (int i = 1; i <= N; i++) {
		int temp;
		scanf("%d", &temp);
		sum[i] = sum[i - 1] + temp;
	}

	for (int i = 1; i <= M; i++) {
		int a, b;
		scanf("%d%d", &a, &b);

		printf("%d\n", sum[b] - sum[a - 1]);
	}

	return 0;
}

#endif
//구간합 구하기 4

#if 0
#include <stdio.h>
int map[1024 + 1][1024 + 1];
int N, M;


int main() {
	scanf("%d%d", &N, &M);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int a;
			scanf("%d", &a);
			map[i][j] = map[i - 1][j] + map[i][j - 1] + a - map[i - 1][j - 1];
		}
	}


	for (int i = 1; i <= M; i++) {
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		printf("%d\n", map[x2][y2] - map[x1 - 1][y2] - map[x2][y1 - 1] + map[x1 - 1][y1 - 1]);
	}

	return 0;
}

#endif
//구간합 구하기 5

#if 0
#include <stdio.h>
#include <stdlib.h>

using namespace std;

typedef struct node_ {
	int data;
	int index;
}node;


int N;
int numbers[1000000 + 1];
int indexList[1000000 + 1];
node *list[1000000 + 1];

void sort(int s, int e) {
	if (s >= e)
		return;

	int T = s, L = s;
	int P = e;

	while (T < P) {
		if (list[T]->data > list[P]->data) {
			node *temp = list[T];
			list[T] = list[L];
			list[L] = temp;
			L++;
		}
		T++;
	}

	node *temp = list[L];
	list[L] = list[P];
	list[P] = temp;

	sort(s, L - 1);
	sort(L + 1, e);
}

int maxIndex = 0;
int main() {
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &numbers[i]);
		node *temp;
		temp = (node *)malloc(sizeof(node));
		temp->data = numbers[i];
		temp->index = i;
		list[i] = temp;
	}

	sort(1, N);


	int maxLength = 0;
	for (int i = 1; i <= N; i++) {
		int temp = list[i]->index;
		if (temp <= N - i && maxLength < temp)
			maxLength = temp;
	}

	printf("%d\n", maxLength);

	for (int i = N; i >= 1; i--) {
		int max = 0;
		for (int j = list[i]->index; j >= 0; j--) {
			if (max < indexList[j])
				max = indexList[j];
		}

		indexList[list[i]->index] = max + 1;
	}

	int i = maxLength;
	int k = N;

	while (i > 0) {
		if (i == indexList[k]) {
			printf("%d ", list[i]->data);
			i--;
		}
		k--;
	}
	return 0;
}
#endif
//LIS5

#if 0
#include <stdio.h>
#include <algorithm>

using namespace std;

int arr[500 * 2 + 2];
int dp[500 + 1][500 + 1];
int N;

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		arr[i] = a;
		arr[i + 1] = b;
	}

	for (int len = 2; len <= N; len++) {
		for (int i = 1; i <= N - len + 1; i++) {
			int j = i + len - 1;
			dp[i][j] = 0x7fffffff;

			for (int k = i; k < j; k++) {
				int cost = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
				dp[i][j] = min(dp[i][j], cost);
			}
		}
	}

	printf("%d", dp[1][N]);
	return 0;
}
#endif
// 행렬의 합

#if 0
#include <stdio.h>
#define MAX_COST 10000

int memory[100 + 1];
int cost[100 + 1];
int dp[100 + 1][100 * 100 + 1];

int N, M, maxC, maxM;


int main() {
	scanf("%d%d", &N, &M);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &memory[i]);
		maxM += memory[i];
	}

	for (int i = 1; i <= N; i++) {
		scanf("%d", &cost[i]);
		maxC += cost[i];
	}

	dp[0][maxC] = maxM;

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= maxC; j++) {
			if (dp[i - 1][j] != 0) {
				if (dp[i][j] < dp[i - 1][j])
					dp[i][j] = dp[i - 1][j];
				if (dp[i][j - cost[i]] < dp[i][j] - memory[i])
					dp[i][j - cost[i]] = dp[i][j] - memory[i];
			}
		}
	}

	int result = 0;

	for (int j = 0; j <= maxC; j++) {
		if (dp[N][j] >= M) {
			result = j;
			break;
		}
	}

	printf("%d", result);

	return 0;
}

#endif
//앱

#if 0
#endif
//LCS2

#if 0
#include <stdio.h>

char s1[4000 + 2];
char s2[4000 + 2];

int dp[4000 + 1][4000 + 1];
int length;

int main() {
	scanf("%s", &s1[1]);
	scanf("%s", &s2[1]);
	int l1 = 1;
	int l2 = 1;

	while (s1[l1]) l1++;
	while (s2[l2]) l2++;

	for (int i = 1; i < l1; i++) {
		for (int j = 1; j < l2; j++) {
			if (s1[i] == s2[j])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = 0;
		}
	}

	int length = 0;

	for (int i = 0; i < l1; i++) {
		for (int j = 0; j < l2; j++) {
			if (length < dp[i][j])
				length = dp[i][j];
		}
	}

	printf("%d\n", length);

	return 0;
}

#endif
//공통부분문자열

#if 0
#include <stdio.h>
#define MOD 1000000007
int column[10000 + 1];
int dp[10000 + 1][10000 + 2];
int N;

int main() {
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &column[i]);
	}

	dp[1][0] = 1;

	for (int i = 2; i <= N; i++) {
		if (column[i] == -1) {
			for (int j = 0; j <= 10000; j++) {
				dp[i][j] = (dp[i - 1][j + 1] + dp[i - 1][j]) % MOD;
				if (j >= 1)
					dp[i][j] += dp[i - 1][j - 1] % MOD;
			}
		}
		else {
			dp[i][column[i]] = (dp[i - 1][column[i] + 1] + dp[i - 1][column[i]]) % MOD;
			if (column[i] >= 1)
				dp[i][column[i]] += dp[i - 1][column[i] - 1] % MOD;
		}
	}

	unsigned long long result = 0;

	if (column[N] == -1) {
		for (int i = 0; i <= 10000; i++) {
			result = (result + dp[N][i]) % MOD;
		}
	}
	else {

	}

	printf("%llu", result);

	return 0;
}

#endif
//재단(ㅁ)

#if 0
#include <stdio.h>

int dp[200][200];
int bulb[200];
int N, K;

int min(int a, int b) {
	return a < b ? a : b;
}

int main() {
	scanf("%d%d", &N, &K);

	for (int i = 0; i < N; i++) {
		scanf("%d", &bulb[i]);
	}

	for (int i = 0; i < N; i++) {
		for (int j = i; j--;) {
			dp[j][i] = 1000000;

			for (int k = j; k < i; k++) {
				dp[j][i] = min(dp[j][i], dp[j][k] + dp[k + 1][i] + (bulb[j] != bulb[k + 1]));
			}
		}
	}

	printf("%d", dp[0][N - 1]);
	return 0;
}

#endif
//전구

#if 0
#include <stdio.h>

int T, N;
int cards[1000 + 1];
int dp[1000 + 1][1000 + 1];

int max(int a, int b) {
	return a < b ? b : a;
}

int min(int a, int b) {
	return a < b ? a : b;
}

int main() {

	scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		scanf("%d", &N);

		for (int i = 1; i <= N; i++)
			scanf("%d", &cards[i]);

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (i > j)
					continue;
				if ((N - i - j) % 2)
					dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]);
				else
					dp[i][j] = max(dp[i + 1][j] + cards[i], dp[i][j - 1] + cards[j]);
			}
		}

		printf("%d\n", dp[1][N]);
	}

	return 0;
}

#endif
//카드게임(ㅁ)

#if 0
#include <stdio.h>
int order[100000 + 1];
int result;

int main() {
	int n;
	int index = 1;
	scanf("%d", &n);

	while (n) {
		order[index++] = n;
		scanf("%d", &n);
	}

	for (int i = 1;;)
		return 0;
}

#endif
//ddr(a)

#if 0
#include <stdio.h>
int map[17][17];
int dp[17][64 * 1024]; // 경로만큼(2^16) dp 배열 생성
int N, minLength = 0x7fffffff;

int min(int a, int b) {
	return a < b ? a : b;
}

int start(int current, int visited) {
	if (visited == (1 << N) - 1)
		return map[current][0];

	int *chk;
	chk = &dp[current][visited];

	if (*chk != 0)
		return *chk;

	*chk = 987654321;

	for (int i = 0; i < N; i++) {
		if (visited &(1 << i))
			continue;
		if (map[current][i] == 0)
			continue;
		*chk = min(*chk, start(i, visited | (1 << i)) + map[current][i]);
	}

	return *chk;
}

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			scanf("%d", &map[i][j]);
	}

	printf("%d", start(0, 1));

	return 0;
}

#endif
//외판원(ㅁ)

#if 0
#include <stdio.h>
int x[3];
int y[3];

int cal() {
	int result = (x[0] * y[1] + x[1] * y[2] + x[2] * y[0])
		- (y[0] * x[1] + y[1] * x[2] + y[2] * x[0]);

	if (result < 0)
		return -1;
	else if (result > 0)
		return 1;
	else
		return 0;
}

int main() {


	for (int i = 0; i < 3; i++)
		scanf("%d%d", &x[i], &y[i]);

	printf("%d", cal());

	return 0;
}
#endif
//ccw

#if 0
#include <stdio.h>
#include <math.h>

double x[10001][2];

int N;
double sumP;

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%lf%lf", &x[i][0], &x[i][1]);

	x[N][0] = x[0][0];
	x[N][1] = x[0][1];

	for (int i = 0; i < N; i++)
		sumP += ((x[i][0] * x[i + 1][1]) / 2 - (x[i + 1][0] * x[i][1]) / 2);


	printf("%.1f", fabs(sumP));

	return 0;
}

#endif
// 다각형의 넓이

#if 0
#include <stdio.h>
#include <set>

using namespace std;

set<int> st;
int line[3000 + 1][4];
int parent[3000 + 1];
int chk[3000 + 1];

int N;

int find(int a) {
	if (parent[a] == a)
		return a;

	return parent[a] = find(parent[a]);
}

void add(int a, int b) {
	int x = find(a);
	int y = find(b);

	parent[y] = x;
}

int btw(int a, int b, int index) {
	int x1 = line[a][0] < line[a][2] ? line[a][0] : line[a][2];
	int x2 = line[a][0] > line[a][2] ? line[a][0] : line[a][2];
	int y1 = line[a][1] < line[a][3] ? line[a][1] : line[a][3];
	int y2 = line[a][1] > line[a][3] ? line[a][1] : line[a][3];

	if (index == 1) {
		if (line[b][0] >= x1 && line[b][0] <= x2 && line[b][1] >= y1 && line[b][1] >= y2)
			return 1;
		else
			return 0;
	}
	else {
		if (line[b][2] >= x1 && line[b][2] <= x2 && line[b][3] >= y1 && line[b][3] >= y2)
			return 1;
		else
			return 0;
	}
	return 0;
}


int online(int a, int b) {
	if (btw(a, b, 2) &&
		((line[a][0] - line[a][2])*(line[b][3] - line[a][1]) ==
		(line[a][1] - line[a][3])*(line[b][2] - line[a][0])))
		return 1;

	if (btw(a, b, 1) &&
		((line[a][0] - line[a][2])*(line[b][1] - line[a][1]) ==
		(line[a][1] - line[a][3])*(line[b][0] - line[a][0])))
		return 1;

	return 0;
}

int getResult(int a, int b) {
	int temp1 = (line[a][0] * line[a][3] + line[a][2] * line[b][1] +
		line[b][0] * line[a][1]) -
		(line[a][2] * line[a][1] + line[b][0] * line[a][3] + line[a][0] * line[b][1]);

	int temp2 = (line[a][0] * line[a][3] + line[a][2] * line[b][3] +
		line[b][2] * line[a][1]) -
		(line[a][2] * line[a][1] + line[b][2] * line[a][3] + line[a][0] * line[b][3]);

	if (temp1 * temp2 < 0)
		return 1;
	else
		return 0;
}

int main() {

	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
		parent[i] = i;

	for (int i = 1; i <= N; i++)
		scanf("%d%d%d%d", &line[i][0], &line[i][1], &line[i][2], &line[i][3]);

	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			if (online(i, j)) {
				add(i, j);
				continue;
			}

			if (getResult(j, i) && getResult(i, j))
				add(i, j);
		}
	}

	for (int i = 1; i <= N; i++) {
		chk[parent[i]]++;
		st.insert(parent[i]);
	}

	printf("%d\n", st.size());

	int max = 0;
	for (int i = 1; i <= N; i++) {
		if (max < chk[i])
			max = chk[i];
	}

	printf("%d", max);

	return 0;
}

#endif

#if 0
#include <stdio.h>

int p[4][2];

int chk(int index) {
	int xSide[2];
	int ySide[2];
	int rest[2];
	int vt1[2][2];
	int xCnt = 0, yCnt = 0, rCnt = 0;

	for (int i = 1; i < 4; i++) {
		if (p[index][0] == p[i][0] && p[index][1] == p[i][1])
			return 0;

		if (p[index][0] == p[i][0]) {
			if ()
				if (xCnt != 0)
					return 0;
			xCnt++;
			xSide[0] = p[i][0];
			xSide[1] = p[i][1];
			continue;
		}
		else if (p[index][1] == p[i][1]) {
			if (yCnt != 0)
				return 0;
			yCnt++;
			ySide[0] = p[i][0];
			ySide[1] = p[i][1];
			continue;
		}
		else {
			if (rCnt != 0)
				return 0;
			rCnt++;
			rest[0] = p[i][0];
			rest[1] = p[i][1];
			continue;
		}


	}

	if (xCnt == 1 && yCnt == 1 && rCnt == 1) {
		vt1[0][0] = xSide[0] - p[index][0];
		vt1[0][1] = xSide[1] - p[index][1];
		vt1[1][0] = ySide[0] - p[index][0];
		vt1[1][0] = ySide[1] - p[index][1];

		if (p[index][0] + vt1[0][0] + vt1[1][0] == rest[0] &&
			p[index][1] + vt1[0][1] + vt1[1][1] == rest[1])
			return 1;

		return 0;
	}

	return 0;
}

int main() {
	int T;

	scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		for (int i = 0; i < 4; i++)
			scanf("%d%d", &p[i][0], &p[i][1]);

		if (chk(0))
			printf("1\n");
		else
			printf("0\n");
	}


	return 0;
}

#endif
//asdfasdf


#if 0
#include <stdio.h>
int rec[4][2];
int a[2];
int b[2];

int meet, zero;
int outR, outL;
int ina, inb;

int min(int a, int b) {
	return a < b ? a : b;
}

int max(int a, int b) {
	return a < b ? b : a;
}

void ccw(int index) {
	int arr[2][4];

	arr[0][0] = a[0]; arr[1][0] = a[1];
	arr[0][1] = b[0]; arr[1][1] = b[1];
	arr[0][2] = rec[index][0]; arr[1][2] = rec[index][1];
	arr[0][3] = a[0]; arr[1][3] = a[1];

	int result = 0;

	for (int i = 0; i < 3; i++)
		result += arr[0][i] * arr[1][i + 1];

	for (int i = 1; i <= 3; i++)
		result -= arr[0][i] * arr[1][i - 1];

	if (result < 0)
		outR++;
	else if (result == 0) {
		if (arr[0][2] >= min(a[0], b[0]) && arr[0][2] <= max(a[0], b[0]) &&
			arr[1][2] >= min(a[1], b[1]) && arr[1][2] <= max(a[1], b[1]))
			meet++;
		else
			zero++;
	}
	else {
		outL++;
	}

}

int main() {

	int T;

	scanf("%d", &T);

	for (int t = 1; t <= T; t++)
	{
		meet = 0; zero = 0;
		outR = outL = 0;
		ina = inb = 0;
		scanf("%d%d%d%d", &rec[0][0], &rec[0][1], &rec[3][0], &rec[3][1]);

		rec[1][0] = rec[0][0];
		rec[2][0] = rec[3][0];
		rec[1][1] = rec[3][1];
		rec[2][1] = rec[0][1];

		scanf("%d%d%d%d", &a[0], &a[1], &b[0], &b[1]);

		if (a[0] >= min(rec[0][0], rec[3][0]) && a[0] <= max(rec[0][0], rec[3][0]) &&
			a[1] >= min(rec[0][1], rec[3][1]) && a[1] <= max(rec[0][1], rec[3][1])) {
			if (a[0] > min(rec[0][0], rec[3][0]) && a[0] < max(rec[0][0], rec[3][0]) &&
				a[1] > min(rec[0][1], rec[3][1]) && a[1] < max(rec[0][1], rec[3][1]))
				ina = 1; // 사각형 안에 있음
			else
				ina = 2; // 사각형 선 위에 있음
		}
		ina = 1;
		if (b[0] >= min(rec[0][0], rec[3][0]) && b[0] <= max(rec[0][0], rec[3][0]) &&
			b[1] >= min(rec[0][1], rec[3][1]) && b[1] <= max(rec[0][1], rec[3][1])) {
			if (b[0] > min(rec[0][0], rec[3][0]) && b[0] < max(rec[0][0], rec[3][0]) &&
				b[1] > min(rec[0][1], rec[3][1]) && b[1] < max(rec[0][1], rec[3][1]))
				inb = 1;
			else
				inb = 2;
		}

		for (int i = 0; i < 4; i++)
			ccw(i);

		switch (ina) {
		case 0:
			if (inb == 0) {
				if (meet == 1 && ((outR == 3 && outL == 0) || (outR == 0 && outL == 3)))
					printf("1\n");
				else if (meet == 0 && (outR == 2 && outL == 2))
					printf("2\n");
			}
			else if (inb == 1) {

			}
			else {

			}
		case 1:
		case 2:
		}
	}

	return 0;
}

#endif
//교차점

#if 01
#include <stdio.h>
#include <cmath>
#include <stdlib.h>
#include <vector>

using namespace std;

typedef struct node_ {
	int index;
	double angle;
}node;

node *list[100000+1];
double dot[100000+1][2];
double vt[2];
vector<node *> q;
int N, x = 40000, y = 40000;

double getAngle(int index) {
	if ((dot[index][0] - vt[0]) == 0) {
		if ((dot[index][1] - vt[1]) < 0)
			return (double)-3.14159265358979323846 / (double)2;
		else
			return (double)3.14159265358979323846 / (double)2;
	}

	return atan((dot[index][1] - vt[1]) / (dot[index][0]-vt[0]));
}

double getDistance(int a, int b) {
	return fabs(sqrt((dot[a][0]-dot[b][0])*(dot[a][0] - dot[b][0]) +
		(dot[a][1] - dot[b][1])*(dot[a][1] - dot[b][1])));
}

void sort(int s, int e) {
	if (s >= e)
		return;

	int T = s, L = s;
	int P = e;

	while (T < P) {
		if (list[T]->angle < list[P]->angle) {
			node *temp = list[L];
			list[L] = list[T];
			list[T] = temp;
			L++;
		}

		if (list[T]->angle == list[P]->angle) {
			if (getDistance(list[0]->index, list[T]->index) < getDistance(list[0]->index, list[P]->index)) {
				node *temp = list[L];
				list[L] = list[T];
				list[T] = temp;
				L++;
			}
		}
		T++;
	}

	node *temp = list[P];
	list[P] = list[L];
	list[L] = temp;

	sort(s, L - 1);
	sort(L + 1, e);
}
int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%lf%lf", &dot[i][0], &dot[i][1]);
		if ((double)y >= dot[i][1]) {
			if ((double)x > dot[i][0])
				x = i;
			y = i;
		}
	}

	vt[0] = dot[x][0];
	vt[1] = dot[y][1];

	node *temp;
	temp = (node *)malloc(sizeof(node));
	temp->index = x;
	temp->angle = 0;
	list[0] = temp;

	for (int i = 1; i < N; i++) {
		if (i == x)
			continue;
		node *temp;
		temp = (node *)malloc(sizeof(node));
		temp->index = i;
		temp->angle = getAngle(i);
		list[i] = temp;
	}

	sort(1, N - 1);

	q.push_back(list[0]);
	q.push_back(list[1]);

	for (int i = 2; i < N; i++) {
		node *temp1, *temp2;
		temp2 = q.back();
		q.pop_back();
		temp1 = q.back();
		q.pop_back();

		//if (temp1->index != 0 && (temp1->angle == temp2->angle)) {
		//	q.push_back(temp2);
		//	i--;
		//	continue;
		//}

		double result = dot[temp1->index][0]* dot[temp2->index][1] +
			dot[temp2->index][0] * dot[list[i]->index][1] + 
			dot[list[i]->index][0] * dot[temp1->index][1] -
			dot[temp2->index][0] * dot[temp1->index][1] -
			dot[list[i]->index][0] * dot[temp2->index][1] -
			dot[temp1->index][0] * dot[list[i]->index][1];

		if (result > 0) {
			q.push_back(temp1);
			q.push_back(temp2);
			q.push_back(list[i]);
		}
		else {
			q.push_back(temp1);
			q.push_back(list[i]);
		}
	}

	printf("%d", q.size());

	for (int i = 0; i < N; i++)
		free(list[i]);

	return 0;
}

#endif
