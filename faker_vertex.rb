module Faker
  class Vertex
    class << self
      # Generates a valid Vertex attributes
      #
      # Example:
      #   Faker::Vertex.description # => "UMSYY"
      #   Faker::Vertex.visited # => true
      #   Faker::Vertex.distnace # => 9
	 
      def description 
        (0...4).map{65.+(rand(25)).chr}.join
      end
    
      def distance
        rand(25)
      end
    
      def visited
        [true,false].sample
      end
  	end
  end
end