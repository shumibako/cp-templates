#include <bits/stdc++.h>
using namespace std;

template <class T>
struct myMatrix
{
    int h, w;
    vector<vector<T>> M;
    myMatrix()
    {
        h = 0;
        w = 0;
        M = vector<vector<T>>(0, vector<T>(0, 0));
    }

    myMatrix(vector<vector<T>> V)
    {
        h = V.size();
        w = V[0].size();
        for (auto v : V)
            assert(v.size() == w);
        M = V;
    }

    vector<vector<T>> transpose()
    {
        vector<vector<T>> V(w, vector<T>(h, 0));
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                V[j][i] = M[i][j];
        swap(h, w);
        return M = V;
    }

    void set_Matrix(vector<vector<T>> V)
    {
        assert(V.size() == h);
        for (auto v : V)
            assert(v.size() == w);
        M = V;
    }

    auto begin() { return M.begin(); }
    auto end() { return M.end(); }

    vector<vector<T>> operator+(myMatrix A)
    {
        assert(h == A.h && w == A.w);
        vector<vector<T>> C(h, vector<T>(w, 0));
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                C[i][j] = M[i][j] + A.M[i][j];
        return C;
    }
    vector<vector<T>> operator+=(myMatrix A)
    {
        assert(h == A.h && w == A.w);
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                M[i][j] += A.M[i][j];
        return M;
    }

    vector<vector<T>> operator-(myMatrix A)
    {
        assert(h == A.h && w == A.w);
        vector<vector<T>> C(h, vector<T>(w, 0));
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                C[i][j] = M[i][j] - A.M[i][j];
        return C;
    }
    vector<vector<T>> operator-=(myMatrix A)
    {
        assert(h == A.h && w == A.w);
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                M[i][j] -= A.M[i][j];
        return M;
    }

    vector<vector<T>> operator*(myMatrix A)
    {
        assert(w == A.h);
        vector<vector<T>> C(h, vector<T>(A.w, 0));
        for (int i = 0; i < h; i++)
            for (int j = 0; j < A.w; j++)
                for (int k = 0; k < w; k++)
                    C[i][j] += M[i][k] * A.M[k][j];
        return C;
    }
    vector<vector<T>> operator*=(myMatrix A)
    {
        assert(w == A.h);
        vector<vector<T>> C(h, vector<T>(A.w, 0));
        for (int i = 0; i < h; i++)
            for (int j = 0; j < A.w; j++)
                for (int k = 0; k < w; k++)
                    C[i][j] += M[i][k] * A.M[k][j];
        M = C;
        return M;
    }

    vector<vector<T>> operator^(myMatrix A)
    {
        assert(h == A.h && w == A.w);
        vector<vector<T>> C(h, vector<T>(w, 0));
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                C[i][j] = M[i][j] ^ A.M[i][j];
        return C;
    }
    vector<vector<T>> operator^=(myMatrix A)
    {
        assert(h == A.h && w == A.w);
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                M[i][j] ^= A.M[i][j];
        return M;
    }

    vector<vector<T>> operator&(myMatrix A)
    {
        assert(h == A.h && w == A.w);
        vector<vector<T>> C(h, vector<T>(w, 0));
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                C[i][j] = M[i][j] & A.M[i][j];
        return C;
    }
    vector<vector<T>> operator&=(myMatrix A)
    {
        assert(h == A.h && w == A.w);
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                M[i][j] &= A.M[i][j];
        return M;
    }

    vector<vector<T>> operator|(myMatrix A)
    {
        assert(h == A.h && w == A.w);
        vector<vector<T>> C(h, vector<T>(w, 0));
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                C[i][j] = M[i][j] | A.M[i][j];
        return C;
    }
    vector<vector<T>> operator|=(myMatrix A)
    {
        assert(h == A.h && w == A.w);
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                M[i][j] |= A.M[i][j];
        return M;
    }

    vector<vector<T>> operator=(myMatrix A)
    {
        h = A.h;
        w = A.w;
        M = A.M;
        return M;
    }

    bool operator==(myMatrix A)
    {
        if (h != A.h || w != A.w)
            return false;
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                if (M[i][j] != A.M[i][j])
                    return false;
        return true;
    }

    vector<vector<T>> pow(long long k)
    {
        assert(h == w);
        vector<vector<T>> res(h, vector<T>(w, 0));
        vector<vector<T>> P = M;
        for (int i = 0; i < h; i++)
            res[i][i] = 1;
        while (k > 0)
        {
            if (k & 1)
            {
                vector<vector<T>> tmp(h, vector<T>(w, 0));
                for (int i = 0; i < h; i++)
                    for (int j = 0; j < w; j++)
                        for (int k = 0; k < h; k++)
                            tmp[i][j] += res[i][k] * P[k][j];
                res = tmp;
            }
            {
                vector<vector<T>> tmp(h, vector<T>(w, 0));
                for (int i = 0; i < h; i++)
                    for (int j = 0; j < w; j++)
                        for (int k = 0; k < h; k++)
                            tmp[i][j] += P[i][k] * P[k][j];
                P = tmp;
            }
            k >>= 1;
        }
        return res;
    }

    vector<vector<T>> inv()
    {
        assert(h == w);
        vector<vector<T>> invM(h, vector<T>(h, 0));
        vector<vector<T>> aug(h, vector<T>(2 * h, 0));

        // Create augmented matrix [M | I]
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < h; j++)
            {
                aug[i][j] = M[i][j];
            }
            aug[i][i + h] = 1;
        }

        // Perform Gaussian elimination
        for (int i = 0; i < h; i++)
        {
            // Find pivot
            T pivot = aug[i][i];
            assert(pivot != 0); // Ensure matrix is invertible
            for (int j = 0; j < 2 * h; j++)
            {
                aug[i][j] /= pivot;
            }
            for (int k = 0; k < h; k++)
            {
                if (k == i)
                    continue;
                T factor = aug[k][i];
                for (int j = 0; j < 2 * h; j++)
                {
                    aug[k][j] -= factor * aug[i][j];
                }
            }
        }

        // Extract inverse matrix
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < h; j++)
            {
                invM[i][j] = aug[i][j + h];
            }
        }

        return invM;
    }

    void print()
    {
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                cout << M[i][j];
                if (j != w - 1)
                    cout << ' ';
            }
            cout << '\n';
        }
    }
};
