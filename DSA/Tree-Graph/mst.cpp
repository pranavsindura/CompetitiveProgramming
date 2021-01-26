/*
    Minimum Spanning Trees
    Kirchoff's Theorem tells us how many MSTs are possible

    MST is a tree such that the sum of the weights of the edges is as small as possible
    It will have n - 1 edges

    A tree is MST of itself

    Finding MST
    1. Kruskal's MST with DSU
        Sort the edges
        Join together the edges using a DSU
        If the edge is joined, then it is part of MST
        
    2. Prim's MST

    2nd MST

    Find the first MST and its edges
    Now one by one, ignore 1 edge of the MST and find a new MST
    The minimum out of those is the 2nd MST
*/