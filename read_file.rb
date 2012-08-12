module ReadFile
	class Line
    class << self
      
      def read_line
        current = {:description => "", :text => "", :quality => "", :stats => ""}
        File.open("grafo.txt", "r").each_line do |line|
          puts line
        end
      end
      
    end
  end
end