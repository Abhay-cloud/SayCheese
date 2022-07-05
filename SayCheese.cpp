#include <iostream>
#include <cmath>
using namespace std;

double calculateDistance(int h, int r[100], int holeCoordinates[3], int miteCoordinates[3]);

int main()
{
    int h, r[100], temp = 0;
    int holeCoordinates[3], ameliaCoordinates[3], miteCoordinates[3];
    cout << "Enter the number of holes: ";
    cin >> h;
    if (h != 0)
    {
        while (temp < h)
        {
            for (int i = 0; i < 3; i++)
            {
                cout << "Enter the co-ordinate " << i + 1 << ": ";
                cin >> holeCoordinates[i];
            }
            // checking hole coordinates
            if (holeCoordinates[0] != holeCoordinates[1] || holeCoordinates[1] != holeCoordinates[2] || holeCoordinates[0] != holeCoordinates[2])
            {
                // for axis

                cout << "Please enter the same coordinates of hole.";
                return -1;
            }

            cout << "Enter the radius of hole: ";
            cin >> r[temp];
            temp++;
        }
    }
    // for(int i = 1; i <= 3; i++){
    //     cout<<"Enter the Amelia's coordinate "<< i<<": ";
    //     cin >> ameliaCoordinates[i];
    // }
    for (int i = 0; i < 3; i++)
    {
        cout << "Enter the Mite's coordinate " << i + 1 << ": ";
        cin >> miteCoordinates[i];
    }

    // there is no hole between mite and amelia
    if (holeCoordinates[0] > miteCoordinates[0])
    {
        double d = calculateDistance(h, r, holeCoordinates, miteCoordinates);
        cout << "Travel time: " << d * 10 << " sec";
    }
    // if there is any hole present
    else
    {
        double d = calculateDistance(h, r, holeCoordinates, miteCoordinates);
        // cout << d;
        if (h == 1)
        {
            cout << "Travel time: " << (d - (r[0] * 2)) * 10 << " sec";
        }
        else
        {
            double rr = 0;
            // cout << "Size: " << sizeof(r) / sizeof(int) << "\n";
            for (int i = 0; i < h; i++)
            {
                rr += r[i] * 2;
            }
            cout << rr;
            cout << "Travel time: " << (d - (rr)) * 10 << " sec";
        }
    }
}

double calculateDistance(int h, int r[100], int holeCoordinates[3], int miteCoordinates[3])
{
    double d = 0;
    for (int i = 0; i < 3; i++)
    {
        d += miteCoordinates[i] * miteCoordinates[i];
    }
    d = sqrt(d);
    // cout<<"Travel time: "<<d*10 << " sec";
    return d;
}
