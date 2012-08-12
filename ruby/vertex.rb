include Comparable

class Vertex
    attr_accessor :description
    attr_accessor :distance
    attr_accessor :visited
    attr_accessor :parent
    attr_accessor :edges
    attr_accessor :neighbors
    
    def build
      @description = "euahea"
    end
    
    def intialize args = {}
      @description,@distance,@visited,@parent,@edges,@neighbors = args[:description] || "",args[:distance] || 0, args[:visited] || false ,args[:parent] || 0,args[:edges] || 0,args[:neighbors] || 0
    end
        
    def <=>(anOther)
        self.distance <=> anOther.distance
    end
    
end
