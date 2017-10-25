template <typename T>
class TreeNode {
	T data;
	TreeNode** children;
	int childrenCount;
	int max;
	public:
	TreeNode(T data) {
		this->data = data;
		max = 50;
		children = new TreeNode*[max];
		childrenCount = 0;
	}

	int numChildren() {
		return childrenCount;
	}

	void addChild(TreeNode* child) {
		if (childrenCount >= max) {
			return;
		}
		this->children[childrenCount] = child;
		childrenCount++;
	}

	void setChild(int i, TreeNode* child) {
		if (i >= childrenCount) {
			return;
		}
		this->children[i] = child;
	}

	TreeNode* getChild(int i) {
		if (i >= childrenCount) {
			return NULL;
		}
		return this->children[i];
	}

	T getData() {
		return data;
	}

	void setData(T data) {
		this->data = data;
	}

};
