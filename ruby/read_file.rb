module ReadFile
	class Line
    class << self
      
      def read_line
        current = {:description => "", :text => "", :quality => "", :stats => ""}
        File.open("grafo.txt", "r").each_line do |line|
          t = line.split("/")
          t
        end
      end
      
    end
  end
end