require_relative 'loader'
require_relative 'branch_tree'

############## Loader test
=begin
puts dataset.getMap(111)
puts dataset.getFlower(12)
=end

=begin
branch_tree = Tree.new("branch.csv")
branch_tree.printAll
=end

dataset = Dataset.new
branch = BranchTree::Branch.new("branch.csv")

while true do
	branch.question
	input = gets.chomp.to_i
	if input == -1
		branch.movePreviousBranch
	elsif input == -100
		break
	else
		result = branch.moveNextBranch(input)
		if result % 10 != 0
			puts "\n\n"
			print "당신의 선택지는 : "
			branch.showAllAnswer
			arr = Array.new
			dataset.getMap(result).each do |k,v|
				if v != nil
					v.each do |w|
						arr << w
					end
				end
			end
			arr.each do |v|
				puts dataset.getFlower(v)[:NAME] + " : " + dataset.getFlower(v)[:MEANINGS]
			end
			puts "\n\n\n\n"
			branch.movePreviousBranch
			branch.movePreviousBranch
			branch.movePreviousBranch
		end
	end
end