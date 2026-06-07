class Solution {
public:

    int maxWidthOfVerticalArea(std::vector<std::vector<int>>& points) {
        // Step 1: Extract all x-coordinates
        std::vector<int> x_coords;
        x_coords.reserve(points.size()); // Optimize memory allocation
        
        for (const auto& point : points) {
            x_coords.push_back(point[0]);
        }
        
        // Step 2: Sort the x-coordinates
        std::sort(x_coords.begin(), x_coords.end());
        
        // Step 3: Find the maximum gap between consecutive x-coordinates
        int max_width = 0;
        for (size_t i = 1; i < x_coords.size(); ++i) {
            int width = x_coords[i] - x_coords[i - 1];
            if (width > max_width) {
                max_width = width;
            }
        }
        
        return max_width;
    }
};