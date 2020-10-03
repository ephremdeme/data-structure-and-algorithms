
using System;
using System.Collections.Generic;
using DataStructures.Graphs;

namespace Algorithms.Graphs
{
    public class DijkstraAllPairsShortestPaths<TGraph, TVertex>
        where TGraph : IGraph<TVertex>, IWeightedGraph<TVertex>
        where TVertex : IComparable<TVertex>
    {

        Dictionary<TVertex, DijkstraShortestPaths<TGraph, TVertex>> _allPairsDjkstra;

        public DijkstraAllPairsShortestPaths(TGraph Graph)
        {
            if (Graph == null)
                throw new ArgumentNullException();

            // Initialize the all pair
            _allPairsDjkstra = new Dictionary<TVertex, DijkstraShortestPaths<TGraph, TVertex>>();

            var vertices = Graph.Vertices;

            foreach (var vertex in vertices)
            {
                var dijkstra = new DijkstraShortestPaths<TGraph, TVertex>(Graph, vertex);
                _allPairsDjkstra.Add(vertex, dijkstra);
            }
        }


        public bool HasPath(TVertex source, TVertex destination)
        {
            if (!_allPairsDjkstra.ContainsKey(source) || !_allPairsDjkstra.ContainsKey(destination))
                throw new Exception("Either one of the vertices or both of them don't belong to Graph.");

            return _allPairsDjkstra[source].HasPathTo(destination);
        }


        /// Returns the distance between source vertex and destination vertex.
        public long PathDistance(TVertex source, TVertex destination)
        {
            if (!_allPairsDjkstra.ContainsKey(source) || !_allPairsDjkstra.ContainsKey(destination))
                throw new Exception("Either one of the vertices or both of them don't belong to Graph.");

            return _allPairsDjkstra[source].DistanceTo(destination);
        }

        /// Returns an enumerable collection of nodes that specify the shortest path from source vertex to destination vertex.
        public IEnumerable<TVertex> ShortestPath(TVertex source, TVertex destination)
        {
            if (!_allPairsDjkstra.ContainsKey(source) || !_allPairsDjkstra.ContainsKey(destination))
                throw new Exception("Either one of the vertices or both of them don't belong to Graph.");

            return _allPairsDjkstra[source].ShortestPathTo(destination);
        }

    }

}

