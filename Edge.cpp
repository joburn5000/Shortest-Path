#include "Edge.h"

Edge::Edge(City s, City e) {
    start_ = s;
    end_ = e;
}
City Edge::getStart() {
    return start_;
}
City Edge::getEnd() {
    return end_;
}
double Edge::getDist() {
    return start_.getDistance(end_);
}