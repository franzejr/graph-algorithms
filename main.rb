#Some Graph Examples methods
require_relative 'graph'

  puts "Testing Class Graph"
  g = Graph.new

  g.add_vertex 4
  g.add_vertex 5
  g.add_vertex 77

  puts g.vertexes
  
  puts "Testing Class Vertex"
  
  hash = {:description=>"" }
  v = Vertex.new 
  v.description = "heaueha"
  puts v.new
