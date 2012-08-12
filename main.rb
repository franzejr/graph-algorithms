#Some Graph Examples methods
require_relative 'graph'
require_relative 'faker_vertex'
require_relative 'read_file'

  puts "Testing Class Graph"
  g = Graph.new

  g.add_vertex 4
  g.add_vertex 5
  g.add_vertex 77

  puts g.vertexes
  
  puts "Testing Class Vertex"
  
  #hash = {:description=>"" }
  #v = Vertex.build
  #v.description = "heaueha"
  #puts v.new

  puts Faker::Vertex.description
  puts Faker::Vertex.distance
  
  puts "Lendo arquivo"
  puts ReadFile::Line.read_line