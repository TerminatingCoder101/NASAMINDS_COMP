#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

vector<int> getPos(int sensors[]) {
  unsigned int zone = 0;

  for (int i = 0; i < 15; i++) {
    if (i == 0 && sensors[i] != 0) {
      zone += 1;
    } else if (sensors[i] != 0) {
      zone += (1 << i);
    }
  }
  
  vector<int> pos(2);

  switch (zone) {
    case 0b0000000000000011:
      pos[0] = 1;
      pos[1] = 8;
      break;
    case 0b0000000000010011:
      pos[0] = 3;
      pos[1] = 3;
      break;
    case 0b0000000000010001:
      pos[0] = 8;
      pos[1] = 1;
      break;
    case 0b0000000100010001:
      pos[0] = 13;
      pos[1] = 3;
      break;
    case 0b0000000100010011:
      pos[0] = 11;
      pos[1] = 6;
      break;
    case 0b0000000000110011:
      pos[0] = 8;
      pos[1] = 8;
      break;
    case 0b0000000000100011:
      pos[0] = 3;
      pos[1] = 13;
      break;
    case 0b0000000000100010:
      pos[0] = 8;
      pos[1] = 15;
      break;
    case 0b0000000000110010:
      pos[0] = 13;
      pos[1] = 13;
      break;
    case 0b0000000100010010:
      pos[0] = 14;
      pos[1] = 11;
      break;
    case 0b0000000100010000:
      pos[0] = 15;
      pos[1] = 8;
      break;
    case 0b0000000000100100:
      pos[0] = 8;
      pos[1] = 16;
      break;
    case 0b0000000000101100:
      pos[0] = 3;
      pos[1] = 18;
      break;
    case 0b0000000001100100:
      pos[0] = 13;
      pos[1] = 18;
      break;
    case 0b0000000000001100:
      pos[0] = 1;
      pos[1] = 23;
      break;
    case 0b0000000001101100:
      pos[0] = 8;
      pos[1] = 23;
      break;
    case 0b0000001001000100:
      pos[0] = 14;
      pos[1] = 20;
      break;
    case 0b0000001001001100:
      pos[0] = 11;
      pos[1] = 25;
      break;
    case 0b0000000001001100:
      pos[0] = 3;
      pos[1] = 28;
      break;
    case 0b0000001001000000:
      pos[0] = 15;
      pos[1] = 23;
      break;
    case 0b0000000001001000:
      pos[0] = 8;
      pos[1] = 30;
      break;
    case 0b0000001001001000:
      pos[0] = 13;
      pos[1] = 28;
      break;
    case 0b0000100110000000:
      pos[0] = 18;
      pos[1] = 3;
    case 0b0000100010000000:
      pos[0] = 23;
      pos[1] = 1;
      break;
    case 0b0001100010000000:
      pos[0] = 28;
      pos[1] = 3;
      break;
    case 0b0000000110000000:
      pos[0] = 16;
      pos[1] = 8;
      break;
    case 0b0001100110000000:
      pos[0] = 23;
      pos[1] = 8;
      break;
    case 0b0001100000000000:
      pos[0] = 30;
      pos[1] = 8;
      break;
    case 0b0001000110000000:
      pos[0] = 18;
      pos[1] = 13;
      break;
    case 0b0001000100000000:
      pos[0] = 23;
      pos[1] = 15;
      break;
    case 0b0001100100000000:
      pos[0] = 28;
      pos[1] = 13;
      break;
    case 0b0010011000000000:
      pos[0] = 18;
      pos[1] = 18;
      break;
    case 0b0010001000000000:
      pos[0] = 23;
      pos[1] = 16;
      break;
    case 0b0110001000000000:
      pos[0] = 28;
      pos[1] = 18;
      break;
    case 0b0000011000000000:
      pos[0] = 16;
      pos[1] = 23;
      break;
    case 0b0110011000000000:
      pos[0] = 23;
      pos[1] = 23;
      break;
    case 0b0100011000000000:
      pos[0] = 18;
      pos[1] = 28;
      break;
    case 0b0100010000000000:
      pos[0] = 23;
      pos[1] = 30;
    case 0b0110000000000000:
      pos[0] =30;
      pos[1] = 23;
      break;
    case 0b0110010000000000:
      pos[0] = 28;
      pos[1] = 28;
      break;
  };

  return pos;
}

int main() {
  vector<int> pos;

  pos = getPos(new int[] {1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0});
  cout << "sensors: 1, 2" << ", coordinates: (" << pos[0] << ", " << pos[1] << ")";
  cout << endl;
  fill(pos.begin(), pos.end(), 0);

  pos = getPos(new int[] {0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0});
  cout << "sensors: 3, 4" << ", coordinates: (" << pos[0] << ", " << pos[1] << ")";
  cout << endl;
  fill(pos.begin(), pos.end(), 0);

  pos = getPos(new int[] {0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0});
  cout << "sensors: 4, 7" << ", coordinates: (" << pos[0] << ", " << pos[1] << ")";
  cout << endl;
  fill(pos.begin(), pos.end(), 0);

  pos = getPos(new int[] {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1});
  cout << "sensors: 11, 15" << ", coordinates: (" << pos[0] << ", " << pos[1] << ")";
  cout << endl;
  fill(pos.begin(), pos.end(), 0);

  pos = getPos(new int[] {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0});
  cout << "sensors: 12, 13" << ", coordinates: (" << pos[0] << ", " << pos[1] << ")";
  cout << endl;
  fill(pos.begin(), pos.end(), 0);

  pos = getPos(new int[] {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0});
  cout << "sensors: 8, 12" << ", coordinates: (" << pos[0] << ", " << pos[1] << ")";
  cout << endl;
  fill(pos.begin(), pos.end(), 0);

  pos = getPos(new int[] {1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0});
  cout << "sensors: 1, 5" << ", coordinates: (" << pos[0] << ", " << pos[1] << ")";
  cout << endl;
  fill(pos.begin(), pos.end(), 0);

  pos = getPos(new int[] {0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0});
  cout << "sensors: 2, 6" << ", coordinates: (" << pos[0] << ", " << pos[1] << ")";
  cout << endl;
  fill(pos.begin(), pos.end(), 0);

}

