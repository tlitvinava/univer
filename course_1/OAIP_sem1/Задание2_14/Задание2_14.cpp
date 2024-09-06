#include <iostream>

int main()
{
    long long W, H, x1, y1, x2, y2, w, h, res, up,up2,up3, down, right,right2,right3, left;
    std::cin >> W >> H >> x1 >> y1 >> x2 >> y2 >> w >> h;

 
        res = 1e18;
        long long a, b, l, h1;
        a = W - w;
        b = H - h;
        l = x2 - x1;
        h1 = y2 - y1;
        up = h - y1;
        down = y2 - b;
        right = w - x1;
        left = x2 - a;
        up2 = H - y1;
        up3 = H - y2;
        right2 = W - x2;
        right3 = W - x1;

        if (x1 > w || y1 > h) {
            std::cout << 0;
            return 0;
        }

        if (h1 <= b) { // (0;0)
            res = std::min(up, res);

        }
        if (l <= a) {
            res = std::min(right, res);
        }

        if (h1 <= b) {// (0;H)
            res = std::min(up2, res);

        }
        if (l <= a) {
            res = std::min(right2, res);
        }

        if (h1 <= b) {//(W;0)
            res = std::min(up, res);

        }
        if (l <= a) {
            res = std::min(right3, res);
        }

        if (h1 <= b) {//(W;H)
            res = std::min(up3, res);

        }
        if (l <= a) {
            res = std::min(right2, res);
        }

        if (res == 1e18) {
            std::cout << -1;
        }
        else {
            std::cout << res;
        }

    return 0;
}

