require 'csv'

class Dataset
	@@map_table = Hash.new # STATE_ID => FLOWER_ID s
	@@flower_table = Hash.new # FLOWER_ID => FLOWER's NAME, FLOWER's MEANING
	
	def initialize
		loadMap
		loadFlower
	end

	def loadMap
		csv_data = CSV.parse(File.read("map.csv"),headers: true)
		for i in 0...csv_data.size
			if csv_data[i]["FLOWER"] != "N"
				tmp_hash = Hash.new
				key = csv_data[i]["ID"].to_i
				#tmp_hash[:STATE] = csv_data[i]["STATE"]
				#tmp_hash[:FLOWER] = csv_data[i]["FLOWER"]
				tmp_hash[:RED] = csv_data[i]["RED"] ? csv_data[i]["RED"].split(",").map { |s| s.to_i } : nil
				tmp_hash[:WHITE] = csv_data[i]["WHITE"] ? csv_data[i]["WHITE"].split(",").map { |s| s.to_i } : nil
				tmp_hash[:BLUE] = csv_data[i]["BLUE"] ? csv_data[i]["BLUE"].split(",").map { |s| s.to_i } : nil
				tmp_hash[:YELLOW] = csv_data[i]["YELLOW"] ? csv_data[i]["YELLOW"].split(",").map { |s| s.to_i } : nil
				tmp_hash[:PURPLE] = csv_data[i]["PURPLE"] ? csv_data[i]["PURPLE"].split(",").map { |s| s.to_i } : nil
				tmp_hash[:ORANGE] = csv_data[i]["ORANGE"] ? csv_data[i]["ORANGE"].split(",").map { |s| s.to_i } : nil
				@@map_table[key]= tmp_hash
			end
		end
	end

	def loadFlower
		csv_data = CSV.parse(File.read("flower.csv"),headers: true)
		for i in 0...csv_data.size
			tmp_hash = Hash.new
			key = csv_data[i]["ID"].to_i
			tmp_hash[:NAME] = csv_data[i]["NAME"]
			tmp_hash[:MEANINGS] = csv_data[i]["MEANINGS"]
			@@flower_table[key] = tmp_hash
		end
	end

	def getMap(state_id)
		#return flowers matching to selected state
		@@map_table[state_id] 
	end

	def getFlower(flower_id)
		@@flower_table[flower_id]
	end

end
