class Node {
	constructor(data, next = null) {
		this.data = data;
		this.next = next;
	}
}

class Linklist {
	constructor(head = null) {
		this.head = head
		this.size = 0;
	}

	// insert Node in Starting 
	insertFirst(data) {
		this.head = new Node(data, this.head);
		this.size++;
	}

	// Insert Last
	insertLast(data) {
		let node = new Node(data);
		let current;

		if (!this.head) {
			this.head = node;
		}
		else {
			current = this.head;
			while (current.next) {
				current = current.next;
			}
			current.next = node;
		}
		this.size++;
	}

	//  Insert On Index
	insertAt(data, index) {
		// out of range
		if (index > 0 && index > this.size) {
			console.log("Index of Out Of Range");
			return {status:false,message:"Index of Out Of Range"};
		}

		// index is first
		if (index == 0) {
			this.insertFirst(data);
			return;
		}

		// index is last
		if (index === this.size) {
			this.insertLast(data);
			return;
		}

		const node = new Node(data);
		let current = this.head, previous, count = 0;

		while (count < index) {
			previous = current; // before 1 then current
			count++;
			current = current.next; // after 1 then prevoius
		}

		node.next = current;
		previous.next = node;
		this.size++;
	}

	// Print list
	get() {
		let current = this.head;
		let data = [];
		while (current) {
			data.push(current);
			current = current.next;
		}
		return data;
	}

	// Get On Index
	getAt(index) {
		let current = this.head;
		let count = 0;
		while (current) {
			if (count == index) {
				return current;
			}
			count++;
			current = current.next;
		}

		return "Not Found";
	}

	// Remove At
	removeAt(index) {
		if (index > 0 && index > this.size) {
			return;
		}

		let current = this.head, previous, count = 0;

		if (index === 0) {
			this.head = current.next;
		}
		else {
			while (count < index) {
				count++;
				previous = current;
				current = current.next;
			}
			previous.next = current.next;
		}

		this.size--;
	}

	// Clear list
	clearList() {
		this.head = null;
		this.size = 0;
	}
}

// let list = new Linklist();
// list.insertFirst(5);
// list.insertLast(450);
// list.insertAt(444, 1);
// console.log(list.get());
// list.getAt(1);
// list.removeAt(1);
// list.clearList();