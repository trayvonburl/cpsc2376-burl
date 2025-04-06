#include <iostream>

struct Point {
    float x;
    float y;
};

// Function to calculate the midpoint between two points (returns a Point object)
Point calcMidpoint(const Point* p1, const Point* p2) {
    // Midpoint formula: midpoint x = (x1 + x2) / 2, midpoint y = (y1 + y2) / 2
    float midpointX = (p1->x + p2->x) / 2.0f;
    float midpointY = (p1->y + p2->y) / 2.0f;

    return Point{ midpointX, midpointY };
}

int main() {
    // Step 1: Create two points with example coordinates
    Point a{ 1.0f, 2.0f };
    Point b{ 5.0f, 6.0f };

    // Step 2: Call calcMidpoint using pointers to 'a' and 'b'
    Point mid = calcMidpoint(&a, &b);

    // Step 3: Print the midpoint coordinates
    std::cout << "Midpoint is at (" << mid.x << ", " << mid.y << ")" << std::endl;  // Should be (3, 4)

    return 0;
}