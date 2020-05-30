require 'csv'

module BranchTree
	class Branch
		def initialize(csv_file_name)
			@branch_tree = Tree.new(csv_file_name)
			@current_node = @branch_tree
			csv_data = CSV.read(csv_file_name)
			@hash = Hash.new
			for i in 1..19
				@hash[csv_data[i][0]] = csv_data[i][1].to_i
			end
		end
		def movePreviousBranch
			if @current_node.parent != nil
				@current_node = @current_node.parent
			end
		end
		def moveNextBranch(user_input)
			######### number_control versioin
			if 0 < user_input and user_input < @current_node.children.size + 1
				@current_node = @current_node.children[user_input-1]
				return @current_node.state_id
			else
				puts "INVALID INPUT : Input must be smaller than options = " + @current_node.children.size.to_s
				return @current_node.state_id
			end

=begin
			######### text_control version
			#
			puts user_input
			puts @hash[user_input]
			if @hash[user_input] == nil
				puts "wrong input"
				return @current_node.state_id
			end
			#
			for i in 0...@current_node.children.size()
				if @current_node.children[i].state_id == @current_node.state_id + @hash[user_input]
					@current_node = @current_node.children[i]
					break
				end
			end
			return @current_node.state_id
=end
		end
		def question
			if @current_node.state_id == 0
				puts "누구에게 줄 건가요?"
				@current_node.printChildren
			elsif @current_node.state_id % 100 == 0
				puts "무슨 목적으로 주는 건가요?"
				@current_node.printChildren
			elsif @current_node.state_id % 10 == 0
				puts "구체적으로 어떤 상황이죠?"
				@current_node.printChildren
			else
				puts "error catched : no question exist"
			end
		end
		def showAllAnswer
			print @current_node.parent.parent.state_text
			print " - " + @current_node.parent.state_text
			print " - " + @current_node.state_text + "\n"
		end
	end
	class Tree
		attr_accessor :children, :parent, :state_id, :state_text
		def initialize(csv_file_name, id = 0, txt = "", pr = nil)
			if id == 0
				csv_data = CSV.read(csv_file_name)
				@state_id = csv_data[0][0].to_i
				@state_text = csv_data[0][1]
				@children = []
				@parent = nil
				for i in 20...csv_data.size
					insert(csv_data[i][0].to_i, csv_data[i][1])
				end
			else
				@state_id = id
				@state_text = txt
				@children = []
				@parent = pr
			end
		end
		def insert(id, txt)
			if id % 100 == 0
				# for the first layer
				node = Tree.new("",id,txt,self)
				@children << node
			elsif id % 10 == 0
				# for the middle layer
				for i in 0...@children.size()
					if 0 < id - @children[i].state_id and id - @children[i].state_id < 100
						node = Tree.new("",id,txt,self.children[i])
						@children[i].children << node
					end
				end
			else
				#for the leaf layer
				for i in 0...@children.size()
					if 0 < id - @children[i].state_id and id - @children[i].state_id < 100
						for j in 0...@children[i].children.size()
							if 0 < id - @children[i].children[j].state_id and id - @children[i].children[j].state_id < 10
								node = Tree.new("",id,txt,self.children[i].children[j])
								@children[i].children[j].children << node
							end
						end
					end
				end
			end
		end
		def printChildren
			for i in 0...@children.size()
				print @children[i].state_text
				if i != @children.size()-1
					print ", "
				end
			end
			puts ""
		end
		def printAll
			for i in 0...children.size()
				for_who = children[i].state_text
				for j in 0...children[i].children.size()
					for_why = children[i].children[j].state_text
					for k in 0...children[i].children[j].children.size()
						for_when = children[i].children[j].children[k].state_text
						id = children[i].children[j].children[k].state_id
						puts id.to_s + ": "+ for_who + "-" + for_why + "-" +for_when
					end
				end
			end
		end
	end
end

branch = BranchTree::Tree.new("branch.csv")
branch.printAll
