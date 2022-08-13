#include <iostream>
using namespace std;

#define LH +1
#define EH 0
#define RH -1

typedef struct BSTNode
{
	int data;
	int bf;
	struct BSTNode* lchild, * rchild;
}BSTNode, * BSTree;

void R_Rotate(BSTree& p)
{
	BSTree lc;

	lc = p->lchild;
	p->lchild = lc->rchild;
	lc->rchild = p;
	p = lc;

	return;
}

void L_Rotate(BSTree& p)
{
	BSTree rc;
	rc = p->rchild;
	p->rchild = rc->lchild;
	rc->lchild = p;
	p = rc;

	return;
}
void LeftBalance(BSTree& T)
{
	//对指针T所致节点为根的二叉树作平衡旋转处理
	BSTree lc;
	lc = T->lchild;
	//检查T节点的左孩子，根据其平衡因子判断是右旋还是左右双旋
	switch (lc->bf)
	{
		//左孩子的平衡因子为1，平衡因子是直线，右旋
	case LH:
		T->bf = EH;
		lc->bf = EH;
		R_Rotate(T);
		break;
		//左孩子平衡因子为-1，平衡因子为折线，左右双旋
	case RH:
		BSTree rd;
		rd = lc->rchild;
		//修改T节点和其左孩子的平衡因子
		switch (rd->bf)
		{
		case LH:
			T->bf = RH;
			lc->bf = EH;
			break;
		case EH:
			T->bf = lc->bf = EH;
			break;
		case RH:
			lc->bf = LH;
			T->bf = EH;
			break;
		}
		rd->bf = EH;
		L_Rotate(T->lchild);
		R_Rotate(T);
	}
}
void RightBalance(BSTree& T)
{
	//对指针T所致节点为根的二叉树作平衡旋转处理
	BSTree rc;

	rc = T->rchild;
	//检查T节点的右孩子，根据其平衡因子判断是左旋还是右左双旋
	switch (rc->bf)
	{
		//右孩子的平衡因子为-1，平衡因子是直线，左旋
	case RH:
		T->bf = EH;
		rc->bf = EH;
		L_Rotate(T);
		break;
		//右孩子平衡因子为-1，平衡因子为折线，右左双旋
	case LH:
		BSTree ld;
		ld = rc->lchild;
		//修改T节点和其右孩子的平衡因子
		switch (ld->bf)
		{
		case LH:
			T->bf = EH;
			rc->bf = RH;
			break;
		case EH:
			T->bf = rc->bf = EH;
			break;
		case RH:
			T->bf = LH;
			rc->bf = EH;
			break;
		}
		ld->bf = EH;
		R_Rotate(T->rchild);
		L_Rotate(T);
	}
}

int InsertAVL(BSTree& T, int e, bool& taller)
{
	if (!T)
	{
		T = (BSTree)malloc(sizeof(BSTNode));
		T->data = e;
		T->lchild = NULL;
		T->rchild = NULL;
		T->bf = EH;
		taller = true;
	}
	else
	{
		//树中已存在和e相同的节点，返回0
		if (T->data == e)
		{
			taller = false;
			return 0;
		}
		//继续在左子树中搜索
		if (T->data > e)
		{
			//说明递归插入失败了
			if (!InsertAVL(T->lchild, e, taller))
			{
				taller = false;
				return 0;
			}
			//到这里说明插入成功，判断平衡因子
			if (taller)
			{
				switch (T->bf)
				{
					//原本左子树比右子树高，再插入以后，平衡因子变为2，此时需要做左平衡处理
				case LH:
					LeftBalance(T);
					taller = false;
					break;
					//原本左右子树,等高，现因左子树增高而使树增高
				case EH:
					taller = true;
					T->bf = LH;
					break;
					//原本右子树比左子树高，现在左右子树登高
				case RH:
					taller = false;
					T->bf = EH;
					break;
				}
			}
		}
		//继续在右子树中搜索
		else
		{
			if (!InsertAVL(T->rchild, e, taller))
			{
				taller = false;
				return 0;
			}
			//到这里说明插入成功，判断平衡因子
			if (taller)
			{
				switch (T->bf)
				{
					//原本左子树比右子树高，插入以后，左右等高
				case LH:
					T->bf = EH;
					taller = false;
					break;
					//原本等高，插入以后，右子树等高
				case EH:
					T->bf = RH;
					taller = true;
					break;
					//原本右子树高，插入以后，平衡因子变为-2，需要做右平衡处理
				case RH:
					RightBalance(T);
					taller = false;
					break;
				}
			}
		}
	}

	return 1;
}

//中序遍历
int temp1[1000],temp2[1000];
int i = 0;
void InorderTraversal(BSTree node)
{
	
	if (!node)
	{
		return;
	}
	else
	{
		InorderTraversal(node->lchild);
		temp1[i] = node->data;
		temp2[i] = node->bf;
		i++;
		InorderTraversal(node->rchild);
	}
	
	return;
}

int main(void)
{
	//flag用于判断是否插入成功，ture为成功,false为失败
	int t;
	cin >> t;
	while (t--)
	{
		// 构建二叉平衡树，并在插入元素时做平衡处理 
		int n, elem;
		cin >> n;
		BSTree T = NULL;
		bool flag = false;
		while (n--)
		{
			cin >> elem;
			InsertAVL(T,elem,flag);
		}
		InorderTraversal(T);
		for (int j = 0; j < i - 1; j++) {
			if (temp1[j] == 0) {
				i = j - 2; break;
			}
		}
		for (int j = 0; j < i - 1; j++) {
		cout << temp1[j] << ':' << temp2[j] << ' ';
		}
		cout << temp1[i - 1] << ':' << temp2[i - 1];
		i = 0;
		cout << endl;
	}
	return 0;
}

