enum RelationType{LESS,GREATER,EQUAL};
class ItemType {
public:
	ItemType(int v = 0) :
		 value(v) {}
	int value;
	int ComparedTo(ItemType rhs)
	{
		if(value <rhs.value){return LESS;}
		else if(value ==rhs.value){return EQUAL;}
		else{return GREATER;}
	}
};

class SortedType {
public:
	int length = 0;
	int currentPos = -1;
	const static int MAX_ITEMS=100;
	ItemType info[MAX_ITEMS];
	void MakeEmpty();
	bool IsFull() const;
	int GetLength()const;
	ItemType GetItem(ItemType item, bool&found);
	void Deleteltem(ItemType item);
	void PutItem(ItemType item);
	void ResetList();
	ItemType GetNextItem();
};

void SortedType::MakeEmpty(){
	length = 0;
}

bool SortedType::IsFull()const {
	return(length-MAX_ITEMS);
}

int SortedType::GetLength()const{
	return length;
}

ItemType SortedType::GetItem(ItemType item,bool&found){
	int midPoint;
	int first=0;
	int last=length-1;
	bool moreToSearch=first<=last;
	found=false;
	while(moreToSearch&&!found){
		midPoint=(first+last)/2;
		switch(item.ComparedTo(info[midPoint])) {
			case LESS:
				last=midPoint-1;
				moreToSearch=first<=last;
				break;
			case GREATER:
				first=midPoint+1;
				moreToSearch=first<=last;
				break;
			case EQUAL:
				found=true;
				item=info[midPoint];
				break;
		}
	}
	return item;
}

void SortedType::Deleteltem(ItemType item) {
	int location=0;
	while(item.ComparedTo(info[location])!=EQUAL)
		location++;
	for(int index=location+1;index<length;index++)
		info[index-1]=info[index];
	length--;
}

void SortedType::PutItem(ItemType item) {
	bool moreToSearch;
	int location=0;
	moreToSearch=(location<length);
	while(moreToSearch) {
		switch(item.ComparedTo(info[location])){
		case LESS:
			moreToSearch=false;
			break;
		case GREATER:
			location++;
			moreToSearch=(location<length);
			break;
		}
	}
	for(int index=length;index>location;index--)
		info[index]=info[index-1];
	info[location]=item;
	length++;
}

void SortedType::ResetList(){
	currentPos=-1;
}

ItemType SortedType::GetNextItem(){
	currentPos++;
	return info[currentPos];
}

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {
	const static std::string inputFileName = "test.in";
	const static std::string outputFileName = "test.out";
	SortedType t;

	std::vector<int> linesIn;
	std::ifstream input;
	input.open(inputFileName);
	while (!input.eof()) {
		int k;
		input >> k;
		linesIn.push_back(k);
	}

	for (int i = 0; i < linesIn.size(); i++) {
		t.PutItem(ItemType(linesIn[i]));
	}

	std::ofstream outputFile;
	outputFile.open(outputFileName);

	for (int i = 0; i < linesIn.size(); i++) {
		int k = t.GetNextItem().value;
		std::cout << k << std::endl;
		outputFile << k << std::endl;
	}

	return 0;
}

