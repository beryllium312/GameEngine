#include "LoadFile.h"
#include <SDL.h>

LoadFile::LoadFile() {}

LoadFile::LoadFile(const char * fileName)
{	
	LoadObj(fileName);
}

void LoadFile::LoadObj(const char * fileName)
{
	ifstream objectFile(fileName);//check to see if the file can is found = null	
	string nextLine;
	int pieceType = -1;
	string tempImageName;
	Vec3 tempPosition;

	if (!objectFile)
	{
		std::cout << "File not found" << std::endl;
	}

	while (getline(objectFile, nextLine))
	{
		string::iterator it = nextLine.begin();

		if (*it == 'f') {
			string tempName;
			// load the rest of the string into a new string and put it in a variable for the filename
			for (auto it2 = it + 2; it2 != nextLine.end(); ++it2) {
				tempName += *it2;
				tempImageName = tempName;
			}
		}
		else if (*it == 'v') {
			Vec3 tempPos;

			tempPos.x = iterateVect(nextLine);//local Vec3 inside the read file function	
			//cout << tempPos.x << endl;
			tempPos.y = iterateVect(nextLine);
			//cout << tempPos.y << endl;
			tempPos.z = iterateVect(nextLine);
			//cout << tempPos.z << endl;

			tempPosition.x = tempPos.x;
			tempPosition.y = tempPos.y;
			tempPosition.z = tempPos.z;
		}
		
		else if (*it == 't') {
			string typestring;
			if (pieceType = -1) {
				for (auto it2 = it + 2; it2 != nextLine.end(); ++it2) {
					typestring += *it2;
				}
				pieceType = std::stoi(typestring);//convert str to int/////changed this to types

				switch (pieceType) {
				case 1:
				case 2:
				case 3:

					makeGamePiece(tempImageName, tempPosition, pieceType);
					break;		

				default:
				cout << "default case" << endl;
					break;
				}
				//if(!EOF)
				continue;
			}else {
				//gameEng.getObjectMap();
				objectFile.close();

			}
		}
	}
}

//Body* LoadFile::makeBody(string imageName_,Vec3 postemp) 
//{	
//	cout << "makeBody" << endl;
//	imageName = imageName_;	
//	position = postemp;
//	return new Body(imageName, position);
//}


void LoadFile::makeGamePiece(std::string imageFile_, Vec3 objVector_, int typeOfPiece_)
{
	static int count = 0;
	count++;

	switch (typeOfPiece_) {
	case 1:
		characterSpriteName = imageFile_;
		CharacterVector = objVector_;
		Body* body = new Body(characterSpriteName, CharacterVector);
		vecOfBodies.insert(std::pair<int, Body*>(count, body));
		break;

	case 2:
		EnemySpriteName = imageFile_;
		EnemyVector = objVector_;
		Body* body = new Body(EnemySpriteName, EnemyVector);
		vecOfBodies.insert(std::pair<int, Body*>(count, body));
		
		break;

	case 3:
		LandSpriteName = imageFile_;
		LandVector = objVector_;
		Body* body = new Body(LandSpriteName, LandVector);
		vecOfBodies.insert(std::pair<int, Body*>(count, body));
		break;

	default:
		break;
	}

}
void populateVectors() {}

float LoadFile::iterateVect(std::string nextLine)
{
	string tempString;
	string tempSt;
	static int c = 0;
	++c;

	auto index = nextLine.find(" ");//find the first space
	tempString = nextLine.substr(index + 1, nextLine.length());
	index = tempString.find(" ");//find the next space after a number
	auto xValue = tempString.substr(0, index);

	tempSt = tempString.substr(index + 1, tempString.length());
	index = tempSt.find(" ");
	auto yValue = tempSt.substr(0, index);

	tempString = tempSt.substr(index + 1, tempSt.length());
	index = tempString.find(EOF);
	auto zValue = tempString.substr(0, index);

	switch (c)
	{
	case 1:
		return std::stof(xValue);//convert to float
		break;

	case 2:
		return std::stof(yValue);//convert to float
		break;

	case 3:
		c = 0;
		return std::stof(zValue);//convert to float		
		break;

	default:
		break;
	}
	return 0;
}

int LoadFile::iterateRect(std::string nextLine)
{
	string tempString;
	string tempSt;
	static int t = 0;
	++t;

	auto index = nextLine.find(" ");
	tempString = nextLine.substr(index + 1, nextLine.length());
	index = tempString.find(" ");
	auto xValue = tempString.substr(0, index);

	tempSt = tempString.substr(index + 1, tempString.length());	//5 length	
	index = tempString.find(" ");//after 5	
	auto yValue = tempSt.substr(0, index);//5 ""

	tempString = tempSt.substr(index + 1, tempSt.length());	//5 length	
	index = tempString.find(" ");
	auto wValue = tempString.substr(0, index);

	tempSt = tempString.substr(index + 1, tempString.length());	//5 length	
	index = tempSt.find(EOF);
	auto hValue = tempSt.substr(0, index);

	switch (t)
	{
	case 1:
		return std::stoi(xValue);//convert to float
		break;

	case 2:
		return std::stoi(yValue);//convert to float
		break;

	case 3:
		return std::stoi(wValue);//convert to float			
		break;

	case 4:
		t = 0;
		return std::stoi(hValue);//convert to float

		break;

	default:
		break;
	}
	return 0;
}

LoadFile::~LoadFile()
{
}
