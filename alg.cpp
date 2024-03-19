#include <iostream>
#include <vector>

using namespace std;

vector<int> getPos15Sensors(int sensors[]) {
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
    case 0b0000000000000001:
      pos[0] = 6;
      pos[1] = 6;
      break;
    case 0b0000000000000010:
      pos[0] = 6;
      pos[1] = 9;
      break;
    case 0b0000000000000100:
      pos[0] = 6;
      pos[0] = 21;
      break;
    case 0b0000000000001000:
      pos[0] = 6;
      pos[1] = 24;
      break;
    case 0b0000000000010000:
      pos[0] = 9;
      pos[1] = 6;
      break;
    case 0b0000000000100000:
      pos[0] = 8;
      pos[1] = 15;
      break;
    case 0b0000000001000000:
      pos[0] = 9;
      pos[1] = 24;
      break;
    case 0b0000000010000000:
      pos[0] = 21;
      pos[0] = 6;
      break;
    case 0b0000000100000000:
      pos[0] = 18;
      pos[1] = 9;
      break;
    case 0b0000001000000000:
      pos[0] = 18;
      pos[1] =  21;
      break;
    case 0b0000010000000000:
      pos[0] = 21;
      pos[0] = 24;
      break;
    case 0b0000100000000000:
      pos[0] = 24;
      pos[1] = 6;
      break;
    case 0b0001000000000000:
      pos[0] = 24;
      pos[0] = 9;
      break;
    case 0b0010000000000000:
      pos[0] = 24;
      pos[0] = 21;
      break;
    case 0b0100000000000000:
      pos[0] = 24;
      pos[0] = 24;
      break;
    default:
      pos[0] = -1;
      pos[1] = -1;
      break;
  };

  return pos;
}

vector<int> getPos12Sensors(int sensors[]) {
  unsigned int zone = 0;
  vector<int> pos;

  for (int i = 0; i < 12; i++) {
    if (sensors[i] != 0) {
      zone += (i << i);
    }
  }

  switch(zone) {
    case 0b0000000000000000:
      pos[0] = 15;
      pos[1] = 15;
      break;
    case 0b0000001000000000:
      pos[0] = 2;
      pos[1] = 28;
      break;
    case 0b0000011100000000:
      pos[0] = 4;
      pos[1] = 26;
      break;
    case 0b0000001100000000:
      pos[0] = 11;
      pos[1] = 26;
      break;
    case 0b0000011000000000:
      pos[0] = 4;
      pos[1] = 19;
      break;
    case 0b0000010100000000:
      pos[0] = 11;
      pos[1] = 19;
      break;
    case 0b0000000100000000:
      pos[0] = 15;
      pos[1] = 22;
      break;
    case 0b0000000010000000:
      pos[0] = 15;
      pos[1] = 22;
      break;
    case 0b0000000011000000:
      pos[0] = 19;
      pos[1] = 26;
      break;
    case 0b0000000011100000:
      pos[0] = 26;
      pos[1] = 26;
      break;
    case 0b0000000010100000:
      pos[0] = 19;
      pos[1] = 19;
      break;
    case 0b0000000001000000:
      pos[0] = 28;
      pos[1] = 28;
      break;
    case 0b0000000001100000:
      pos[0] = 26;
      pos[1] = 19;
      break;
    case 0b0000100000000000:
      pos[0] = 8;
      pos[1] = 15;
      break;
    case 0b0000010000000000:
      pos[0] = 8;
      pos[1] = 15;
      break;
    case 0b0000000000100000:
      pos[0] = 22;
      pos[1] = 15;
      break;
    case 0b0000000000010000:
      pos[0] = 22;
      pos[1] = 15;
      break;
    case 0b0000100000000001:
      pos[0] = 4;
      pos[1] = 11;
      break;
    case 0b0000100000000011:
      pos[0] = 4;
      pos[1] = 4;
      break;
    case 0b0000000000000001:
      pos[0] = 2;
      pos[1] = 2;
      break;
    case 0b0000100000000010:
      pos[0] = 11;
      pos[1] = 11;
      break;
    case 0b0000000000000011:
      pos[0] = 11;
      pos[1] = 4;
      break;
    case 0b0000000000000100:
      pos[0] = 15;
      pos[1] = 8;
    case 0b0000000000000010:
      pos[0] = 15;
      pos[1] = 8;
      break;
    case 0b0000000000010100:
      pos[0] = 19;
      pos[1] = 11;
      break;
    case 0b0000000000001100:
      pos[0] = 19;
      pos[1] = 4;
      break;
    case 0b0000000000011000:
      pos[0] = 26;
      pos[1] = 11;
      break;
    case 0b0000000000011100:
      pos[0] = 26;
      pos[1] = 4;
      break;
    case 0b0000000000001000:
      pos[0] = 28;
      pos[1] = 2;
      break;
    default:
      pos[0] = -1;
      pos[1] = -1;
      break;
  }

  return pos;
}

int main() {
  vector<int> pos;

  pos = getPos15Sensors(new int[] {1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0});
  cout << "sensors: 1, 2" << ", coordinates: (" << pos[0] << ", " << pos[1] << ")";
  cout << endl;
  fill(pos.begin(), pos.end(), 0);

  pos = getPos15Sensors(new int[] {0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0});
  cout << "sensors: 3, 4" << ", coordinates: (" << pos[0] << ", " << pos[1] << ")";
  cout << endl;
  fill(pos.begin(), pos.end(), 0);

  pos = getPos15Sensors(new int[] {0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0});
  cout << "sensors: 4, 7" << ", coordinates: (" << pos[0] << ", " << pos[1] << ")";
  cout << endl;
  fill(pos.begin(), pos.end(), 0);

  pos = getPos15Sensors(new int[] {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1});
  cout << "sensors: 11, 15" << ", coordinates: (" << pos[0] << ", " << pos[1] << ")";
  cout << endl;
  fill(pos.begin(), pos.end(), 0);

  pos = getPos15Sensors(new int[] {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0});
  cout << "sensors: 12, 13" << ", coordinates: (" << pos[0] << ", " << pos[1] << ")";
  cout << endl;
  fill(pos.begin(), pos.end(), 0);

  pos = getPos15Sensors(new int[] {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0});
  cout << "sensors: 8, 12" << ", coordinates: (" << pos[0] << ", " << pos[1] << ")";
  cout << endl;
  fill(pos.begin(), pos.end(), 0);

  pos = getPos15Sensors(new int[] {1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0});
  cout << "sensors: 1, 5" << ", coordinates: (" << pos[0] << ", " << pos[1] << ")";
  cout << endl;
  fill(pos.begin(), pos.end(), 0);

  pos = getPos15Sensors(new int[] {0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0});
  cout << "sensors: 2, 6" << ", coordinates: (" << pos[0] << ", " << pos[1] << ")";
  cout << endl;
  fill(pos.begin(), pos.end(), 0);

}
