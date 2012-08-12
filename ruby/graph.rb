#Including the Vertex Components
require_relative 'vertex'

class Graph 
    attr_accessor :vertexes
  
    def initialize
      @vertexes = []
    end
  
    def add_vertex vertex
      vertexes << vertex
    end
  
    def find_vertex name
        vertexes.each do |vertex|
          if  name.eql? vertex.description vertex; end
        end
    end
end