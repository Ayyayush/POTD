class Solution {
public:
    struct Griderator {
        std::vector<std::vector<int>>& grid;
        int r, c;
        int rMin, rMax, cMin, cMax;
        
        // Primary constructor for starting at the top-left of a layer
        Griderator(std::vector<std::vector<int>>& g, int lvl) : grid(g) {
            rMin = lvl;
            cMin = lvl;
            // Both m and n are even and >= 2 per constraints, so g.size() and g.front() always exist
            rMax = g.size() - 1 - lvl;
            cMax = g.front().size() - 1 - lvl;
            r = rMin;
            c = cMin;
        }

        // Overloaded constructor to "teleport" the iterator to a specific landing spot
        Griderator(std::vector<std::vector<int>>& g, int lvl, int startR, int startC) 
            : Griderator(g, lvl) {
            r = startR;
            c = startC;
        }

        std::pair<int, int> getPos() const { return {r, c}; }

        // State-machine movement: handles corners automatically to traverse the perimeter
        void operator++() {
            if (c == cMin && r < rMax) r++;      // Down the left wall
            else if (r == rMax && c < cMax) c++; // Right along the bottom
            else if (c == cMax && r > rMin) r--; // Up the right wall
            else if (r == rMin && c > cMin) c--; // Left along the top
        }

        int& operator*() { return grid[r][c]; }
    };

    std::vector<std::vector<int>> rotateGrid(std::vector<std::vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid.front().size();
        int numLayers = std::min(m, n) / 2;

        for (int lvl = 0; lvl < numLayers; ++lvl) {
            // 1. Calculate the perimeter of the current layer
            int h = m - 2 * lvl;
            int w = n - 2 * lvl;
            int total = 2 * (h + w) - 4;
            
            // Only rotate if k is not a multiple of the perimeter
            int shift = k % total;
            if (shift == 0) continue;

            // 2. Linearize the layer while tracking the rotation offset
            std::vector<int> layer;
            layer.reserve(total);
            
            Griderator readIt(grid, lvl);
            int ins_i = readIt.r, ins_j = readIt.c; 
            
            for (int i{}; i < total; ++i) {
                layer.push_back(*readIt);
                ++readIt;
                
                // "Odometer" Logic: While reading, we find where the first element 
                // will land after 'k' rotations by sampling the iterator position.
                if (--shift == 0) {
                    std::tie(ins_i, ins_j) = readIt.getPos();
                }
            }

            // 3. Re-insert values starting from the captured landing spot
            // The iterator handles the complex grid-wrapping logic internally.
            Griderator writeIt(grid, lvl, ins_i, ins_j);
            for (int val : layer) {
                *writeIt = val;
                ++writeIt;
            }
        }

        return grid;
    }
};